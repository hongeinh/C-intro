#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void factorial (int n, long *a){
  long fact = 1;
  for(int i = 1; i<=n; i++){
    fact = fact*i;
    *(a+i-1) = fact;
  }
}

int main(){
  int n = 0;
  int k = 0;

  printf("Enter n: ");
  do{
    scanf("%d", &n);
  }while(n<=0);
  
  printf("Enter k: ");
  do{
    scanf("%d", &k);
  }while(k<=0);

  long *a = (long *)malloc(sizeof(long));
  factorial(n, a);
  
  long result = 0;

  //result = *(a+n-2)/( (*(a+k-2)) * (*(a+n-k-1)) ) + *(a+n-2)/( *(a+k-1) * (*(a+n-k-2)));
  result = *(a+n-1)/(*(a+k-1) * *(a+n-k-1));
  result = result % (long) (pow(10,9)+7);
  printf("%ld", result);
  free(a);
  return 0;
  
}
