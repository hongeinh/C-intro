#include<stdio.h>
#include <stdlib.h>

typedef struct singly{
  int id;
  struct singly *next;
}node;



node *head= NULL;



node * makeNode(int i){
  node *p = (node *)malloc(sizeof(node));
  p->id = i;
  p->next = NULL;
  return p;
}


void insertNode(int i, node *eye){
  node *p = makeNode(i);
  if(head == NULL) head = p;
  else{
    if(eye -> next == NULL){
      eye -> next = p;
      p->next = NULL;
    }
    else{
      p->next = eye->next;
      eye->next = p;
    }
  }
}

node *searchNode(int a){
  node *p = head;
  do{
    p = p->next;
  }while(p->id != a);
  return p;
}

void deleteNode(node *eye){
  if(head == NULL) return ;
  if(head == eye) head = eye -> next ;
  else{
    node *p = head;
    while(p->next != eye ) p = p->next;
    p -> next = eye -> next ;
  }

  free(eye);
}


void deleteAll(node *first){
  node *p = first;
  while(p!=NULL){
    first  = first -> next ;
    free(p);
    p = first;
  }
  free(p);
}



void view(node *first){
  node *p = first;
  while( p != NULL){
    printf("%d  ", p->id);
    p = p->next;
  }
  printf("\n");
  free(p);
  
}


int main(){
  for(int i = 0; i < 10; i++){
    insertNode(i, head);
  }
  view(head);
  //deleteAll(head);
  node *st = searchNode(3);
  deleteNode(st);
  
  view(head);
  return 0;
}
