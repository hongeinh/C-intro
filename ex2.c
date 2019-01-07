#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_PRODUCT 10
//===========================================
typedef struct{
       char name[30];
       int quantity;
       double price;
}Product;

Product productList[MAX_PRODUCT];
//===========================================
int inputData(Product *p);
int insertData(Product *p, int number);
void viewInfo(Product *p, int total);
char* toLowercase(char* input);
void searchPro(Product *p, int num);

//===========================================

typedef struct{
  int productID;
  int quantity;
  double total;
}transaction;


transaction transactionList[50];

//===========================================

void makeTransaction(Product *p, transaction *t, int number);

//=======================================================================
//=======================================================================

int main(){
       int choice = 0;
       int num1 = 0; 
       int total = 0;
       char *try = NULL;
       char searchProduct[30];

  //menu 
       do{
	      printf("\n----------BKMart Management System----------\n");
	      printf("1. Input data\n2. Insert data\n3. View product information\n4. Search product information\n5. Product Payment\n6. Exit\n--------------------------------------------\nEnter choice:  ");
	      scanf("%d", &choice);
	      getchar();
	      switch(choice){
		   case 1:
			  num1 = inputData(productList);
			  total = num1;
			  break;
		   case 2:
			  total = insertData(productList, num1);
			  break;
		   case 3:
			  viewInfo(productList, total);
			  break;
		   case 4:
		     // try = toLowercase("NGUYEN Thi HOng Anh");
			  searchPro(productList, total);
			  break;
		   case 5:
			  makeTransaction(productList, transactionList, total);
			  printf("\n           Available in strock\n");
			  viewInfo(productList, total);
			  break;
		   case 6:
			  break;
		   default:
			  printf("Invalid option! Please re_enter!\n");
			  break;
	      }
	      
       }while(choice != 6);
       
       return 0;
}

//========================================================================
//========================================================================



int inputData(Product *p){
       int num = 0;
       do{
	      printf("\nEnter number of products (0<n<=10): ");
	      scanf("%d%*c", &num);

	      if(  num<=0||num>10  )    printf("Invalid! Please re_enter!\n");

       }while(num<=0||num>10);

       //------------------------------------------------------------------
       
       //enter info
       for(int i = 0; i<num; i++){
	      printf("Enter product %d's name: ", i+1);
	      scanf("%[^\n]%*c", (p+i)->name);

	      do{
		     printf("Enter quantity: ");
		     //((p+i)->quantity) = getchar();
		     scanf("%d%*c", &((p + i)->quantity) );
		     if( (p+i)->quantity < 0) printf("Invalid\n");
	      }while((p+i)->quantity <0);

	      do{
		     printf("Enter price: ");
		     scanf("%lf%*c", &((p+i)->price));

		     if( (p+i)->price < 0) printf("Invalid\n");
	      } while( (p+i)->price<=0 );
       }
       return num;
}


//==============================================================================

int insertData(Product *p, int number){
       char continueDoing;
       int use = number;
       int c = 0;
       //----------------------------------------------------------------------
       do{
	 printf("\nInsert new product to the previous list \n\n");
	 //name
	 printf("Enter product %d's full name: ", use+1);
	 scanf("%[^\n]%*c", (p+use)->name );
	 //quantity

	 //...................................................
	 do{
	   printf("Enter product's quantity(>=0):  ");
	   scanf("%d%*c", &((p+use)->quantity) );
	 }while((p+use)->quantity <0);

	 //..................................................
	 
	 //price
	 do{
	   printf("Enter product's price (>0):  ");
	   scanf("%lf%*c",&((p+use)->price) );
	 }while(((p+use)->price) <= 0);
	 //continue
	 //.................................................
	 printf("Do you wish to continue to insert data(Y/N): ");
	 continueDoing = getchar();
	 use++;
       }while(continueDoing != 'N' && continueDoing != 'n');

       return use;
}

//===================================================================================


void viewInfo(Product *p, int total) {
  printf("%-3s %-25s%-10s%-10s\n", "#","Name","Quantity","Price");
       for(int i = 0; i<total; i++){
	      printf("%-3d %-25s%-10d%-5.3lf\n", i, (p+i)->name ,(p+i)->quantity, (p+i)->price );

       }
}

//===================================================================================

char* toLowercase(char* input){

  char * temp = (char *)malloc(sizeof(char));
  strcpy(temp, input);
  int i = 0;
  while(*(temp+i) != '\0'){
    if(*(temp+i)>='A' && *(temp+i)<= 'Z'){
      *(temp+i) = *(temp+i)+32;  //cuz 'A' starts at 65 and 'a' at 97
    }
    i++;
  }
  return temp;
}

//===================================================================================

void searchPro(Product *p, int num){

    int equal = 0;   //if the search item exist 
    char *string1 = (char *)malloc(sizeof(char));
    printf("Enter product to search: ");
    scanf("%[^\n]%*c", string1);
    string1 = toLowercase(string1);

    printf("Searching....\n");
    for(int i = 0; i < num; i++){
      //using tempo strings
      char *string2 = toLowercase((p+i)->name);

      int index = 0;
      while( *(string1+index) == *(string2+index)){
	if( *(string1+index)=='\0' || *(string2+index)=='\0' ){
	  break;
	}
	index++;
      }
      if(*(string1+index)=='\0' && *(string2+index)=='\0'){
	equal = 1;
	printf("%-3d%-20s%-10d  %-5.3lf\n", i, ((p+i)->name), ((p+i)->quantity),  ((p+i)->price) );
      }
    }
    
    if(equal == 0){
      printf("Sorry! Search not found");
    }
}

//==============================================================================================

void makeTransaction(Product *p, transaction *t, int number){
  //input
  int enterID = 0;
  int enterQuantity = 0;
  int totalTransaction = 0;
  char continueDoing;
  double payment = 0;
  
  do{
    printf("Enter productID: ");
    scanf("%d%*c", &enterID);
    printf("Enter quantity: ");
    scanf("%d%*c", &enterQuantity);
    
    //---------------------------------
  
    if(enterID >= number){
      printf("No item!!\n");
    }else{
    
      if(enterQuantity > (p+enterID)->quantity ){
	printf("Not enough items in stock\n");
      }else{
	//nhap id 
	(t+totalTransaction)->productID  =  enterID;
	//nhap so luong lay
	(t+totalTransaction)->quantity  =  enterQuantity;
	//nhap tong tien cua 1 san pham
	(t+totalTransaction)->total  =  ((p+enterID)->price)*enterQuantity;
	//tong tien tat ca san pham
	payment = payment + ((t+totalTransaction)->total);
	//tru so luong available
	(p+enterID)->quantity = ((p+enterID)->quantity) - enterQuantity;
	//tong so lan trao doi
	totalTransaction++;

	//in thong tin trao doi
	printf("%-3s %-20s%-10s%-10s\n", "#","Name","Quantity","Total");
	printf("%-3d %-20s%-10d%-10.3lf\n",enterID, (p+enterID)->name, enterQuantity , ((t+totalTransaction)->total) );
      }
    }
    //---------------------------------------
    do{
      printf("**********Continue purchase?(Y/N):   ");
      scanf("%c%*c", &continueDoing);
      if(continueDoing != 'n' && continueDoing != 'N' && continueDoing != 'y' &&continueDoing != 'Y')
	printf("//////Please enter Y or N!\\\\\\\n");
    }while(continueDoing != 'n' && continueDoing != 'N' && continueDoing != 'y' && continueDoing != 'Y');
    
  }while(continueDoing != 'n'&& continueDoing != 'N');
  printf("**********Payment: %.2lf", payment);
}
