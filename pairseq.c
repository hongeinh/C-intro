#include <stdio.h>
#include <stdlib.h>


int main(){
  int n = 0;
  scanf("%d", &n);
  int *a = (int *) malloc (n*sizeof(int));
  
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }

  int count = 0;
  
  for(int i = 0; i<n-1; i++){
    for(int j = i+1; j < n; j++){
      if(a[i] <a[j]){
	count++;
      }
    }
  }

  printf("%d", count);
  return 0;
}
