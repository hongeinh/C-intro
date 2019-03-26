#include <stdio.h>


int X[100];
int n;

int check(int v, int k){
  if(k==1){
    return 1;
  }
  return (v+X[k-1]<2);
}

void solution(){
  for(int i = 0; i<=n; i++){
    printf("%d", X[i]);
  }
  printf("\n");
}
void TRY(int k){
  for(int v = 0; v<=1; v++){
    if(check(v,k)){
      X[k] = v;
      if(k == n) solution();
      else TRY(k+1);
   }
  }
  
}

int main(){
  n = 4;
  TRY(1);
  
}
