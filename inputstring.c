#include<stdio.h>
#include<stdlib.h>

int main(){
  char input[sizeof(char)];
  scanf("%[^\n]%*c", input);
  printf("%s", input);
  return 0;
  
}
