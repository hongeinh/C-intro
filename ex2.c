#include <stdio.h>

int main(){
     FILE *F1 = fopen("ex1.c","r+");
     FILE *F2 = fopen("deleteComment.txt", "w+");

     if(F1 == NULL) F2 = NULL;
     
     char ch = fgetc(F1);
     while(ch != EOF){
	  if(ch == '/'){
	    //check ky tu tiep theo xem co phai la /* hay // 
	       ch = fgetc(F1);
	       //neu la /*
	       if(ch == '*'){
		 //bo qua tat ca nhung char o trong /* */
		    while(ch != '/'){
		      ch = fgetc(F1);
		    }
	       }
	       else if(ch == '/'){
		 while(ch != '\n'){
		   ch = fgetc(F1);
		 }
	       }
	       else{
		 fputc(ch, F2);
		 ch = fgetc(F1);
	       }
	  }
	  else{
	       fputc(ch, F2);
	       ch = fgetc(F1);
	  }
     }

     
     fclose(F2);
     fclose(F2);
     
     return 0;
}
