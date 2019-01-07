#include <stdio.h>
#include <stdlib.h>

int compareNum(const void * a, const void * b){
  return (*(int *)b -*(int *)a);
}
int main (){
  int arr[] = {92,96,23,35,44,63,78,54,2,1};
  qsort(arr, 10, sizeof(int), compareNum);
  for(int i = 0; i<10; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
