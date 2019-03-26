#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void toLowercase(char *in, char *out){
  for(int i = 0; i<strlen(in); i++){
    if(*(in+i) >='A'&& *(in+i) <= 'Z') *(out+i) = *(in+i) + 32;
    else *(out+i) = *(in+i);
  }
}

int main(){
  char character;
  char input[sizeof(char)];

  scanf("%[^\n]%*c", input);

  char *out = (char *) malloc( (strlen(input)+1)*sizeof(char));

  toLowercase(in, out);

  int occur[26] = {0}; //number of chars in alphabet, initialize all to 0

  for(int i = 0; i<strlen(input); i++){
    occur[*(out+i) - 'a'] ++;
  }

  int maxOccur = -1;

  for(int i = 0; i<26; i++){
    if(occur[i] > maxOccur) maxOccur = occur[i];
  }

  printf("%d", maxOccur);

  free(out);
  return 0;
}
