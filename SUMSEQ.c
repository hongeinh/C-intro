#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int sum(int a[], int num){
  int sum = 0;
  for(int i = 0; i<num; i++){
    if(a[i] >= MOD) a[i] = a[i]%MOD;
    sum = sum + a[i];
    if(sum >= MOD) sum = sum%MOD;
  }
  return sum;
}
int main(){
  int num = 0;
  scanf("%d", &num);
  int *a = (int *)malloc(num*sizeof(int));
  for(int i = 0; i< num ;i++ ){
    scanf("%d", a+i);
  }
  printf("%d", sum(a, num));
  free(a);
  return 0;
  
}
