#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void toUppercase(char *in, char *convert){
  
  for(int i = 0; i<strlen(in); i++){
    if(*(in+i) >="a" && *(in+i) <= "z") *(conver+i) = *(in+i) - 32;
    else *(conver+i) = *(in+i);
  }
  
}



int main(){
  char input[sizeof(char)];
  scanf("%[^\n]", input);

  char *temp = (char *) malloc((strlen(input)+1)*sizeof(char));

  toUppercase(input, temp);

  printf("%s", temp);

  free(temp);

  return 0;
			       
}
