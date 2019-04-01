#include<stdio.h>
//tinh x^n


int expo(int x, int n){
  int temp;
  if(n == 0) return 1;
  else{
    if(n%2 == 0){
      temp = expo(x, n/2);
      return temp * temp;
    }
    else{
      temp = expo(x, n/2);
      return x*temp*temp;
    }
  }
}


int main(){
  int x, n;
  scanf("%d %d", &x, &n);
  printf("%d", expo(x, n));
}
