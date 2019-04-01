#include<stdio.h>
int a[100][100];
int n;


int hasSpecial(){
  int i = 0;
  int j = 0;
  int has = 0;
  
  while(i<n){
    if(i == j){
      if(i == n-1){
	has = 1;
	break;
      }
      else j++;
    }
    else{
      if(j == n-1){
	has = 1;
	break;
      }
      else{
	if(a[i][j] == 0 && a[j][i] == 1) j++;
	else{
	  i++;
	  j = 0;
	}

      }
    }
  }

  return has;
  

}
int main(){

  printf("Enter a number: ");
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    printf("Row: %d\n", i+1 );
    for(int j = 0; j < n; j ++){
      scanf("%d", &a[i][j]);
    }
  }
  printf("Result: %d", hasSpecial());
  return 0;
}
