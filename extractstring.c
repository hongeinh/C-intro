#include<stdio.h>
#include<stdlib.h>

int main(){
  char input[sizeof(char)];
  scanf("%[^\n]", input);
  char delim;
  scanf("%c", &delim);
  for(int i = 0; i<strlen(input); i++){
    if(input[i] != delim) printf("%c", input[i]);
    else printf("\n");
  }
  return 0;
}
