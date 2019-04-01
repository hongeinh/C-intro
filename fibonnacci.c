#include<stdio.h>
//-------> recursive implementation
//may cause some overlapping results

int fibArr[100] = {0};
int fibonn1(int n){
  if(n < 2) return n;
  else return fibonn1(n-1) + fibonn1(n-2);

}

int fibonn2(int n){
  if( n < 2) return n;
  if(fibArr[n] != 0) return fibArr[n];
  else{
    fibArr[n] = fibonn2(n-1)+fibonn2(n-2);
    return fibArr[n];

  }
}


int main(){
  int n;
  scanf("%d", &n);
  fibArr[0] = 1;
  fibArr[1] = 1;
  printf("%d", fibonn2(n));
}
