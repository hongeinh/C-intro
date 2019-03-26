/*#include <stdio.h>
//ICTHUSK

int n;
int x[10];
int count; 
int appeared[10];


int check(int v, int k){
  return (v != 2 && v != 6 && appeared[k] = 0);
}


void solution(){
  int sum = (x[0]*100 + x[1]*10 + x[2]) - (x[3]*100 + 62) + (x[4]*1000+ x[5]*100+x[6]*10 + x[2]);
  if(sum == n) count++;
}


void try(int k){
  for(int v = 1; v<=9; i++){
    if(check(v,k)){
      X[k] = v;
      appeared[v] = 1;
      if(k == 6) solution();
      else TRY(k+1);
      appeared[v] = 0;
      
    }
  }
}

void init(){
  for(int v = 0; v<; v++){
    appeared[v] = 0;
  }
}
int main(){
  scanf("%d", &n);
  count = 0;
  init();
  TRY(0);
}*/


#include <stdio.h>
//ICTHUSK

int n;
int x[10];
int count; 
int appeared[10];


int check(int v, int k){
  return (appeared[v] == 0);
}


void solution(){
  int sum = (x[0]*100 + x[1]*10 + x[2]) - (x[3]*100 + 62) + (x[4]*1000+ x[5]*100+x[6]*10 + x[2]);
  if(sum == n) count++;
}


void TRY(int k){
  for(int v = 1; v<=9; v++){
    if(check(v,k)){
      x[k] = v;
      appeared[v] = 1;
      if(k == 6) solution();
      else TRY(k+1);
      appeared[v] = 0;
      
    }
  }
}

void init(){
  for(int v = 0; v<10; v++){
    appeared[v] = 0;
  }
}
int main(){
  scanf("%d", &n);
  count = 0;
  init();
  TRY(0);
  printf("%d", count);
}
