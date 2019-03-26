/*#include <stdio.h>
#define MAX 100

int n;
int s;
int X[MAX];
int appeared[MAX];


int check(v, k){
  return appeared[v] = 0;
}

void init(){
  for(int i = 0; i <n; i++){
    appeared[i] = 0;
  }
}


int solution(){
  int sum = 0;
  for(int v = 0; i<n; i++){
    if(check(v,k)){
      X[k] = v;
      if()
    }
  }
}

int main(){
  
  scanf("%d %d", &n, &s);
  for(int i = 0; i<n; i++){
    scanf("%d", &X[i]);
  }
  init();
  return 0;
  }*/


#include <stdio.h>
#define MAX 100

int n;
int s;
int count;
int X[MAX];
int appeared[MAX];


int check(int v, int k){
  return 1;
}

/*void init(){
  for(int i = 0; i <n; i++){
    appeared[i] = 0;
  }
}*/

void solution(){
    int sum = 0;
    for(int i = 0; i<n; i++){
        if(appeared[i] == 1){
            sum = sum +X[i];
        }
    }
    if(sum == s) count++;
}

int TRY(int k){
  
  for(int v = 0; v<=1; v++){
    if(check(v,k)){
         appeared[k] = v;
        if(k == n-1) solution();
        else TRY(k+1);
    }
  }
}

int main(){
  
  scanf("%d %d", &n, &s);
  for(int i = 0; i<n; i++){
    scanf("%d", &X[i]);
  }
  //init();
  count = 0;
  TRY(0); 
  printf("%d", count);
  return 0;
}
