#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>


void standardize(char *in, char *out){
  //cut beginning space
  int i = 0;
  while( isspace(*(in+i)) ){
    i++;
  }

  //middle and last space
  int j = 0;
  for(i; i<strlen(in); i++){
    
    if( !isspace(*(in+i)) ){
      
      *(out+j) = *(in+i);
      j++;

    }
    else{

      if( !isspace(*(in+i+1)) ){
	*(out+j) = *(in+i);
	j++;
      }

    }
  }
  
}
int main(){
  char *input = (char *)malloc(sizeof(char));
  scanf("%[^\n]", input);

  char *output = (char *)malloc( (strlen(input)+1) * sizeof(char));

  standardize(input, output);
  printf("%s", output);

  free(input);
  free(output);

  return 0;
  
}
