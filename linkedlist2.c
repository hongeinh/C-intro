#include <stdio.h>
#include <stdlib.h>


typedef struct doubly{
  int id;
  struct doubly *prev;
  struct doubly *next;
}node;



node *head = NULL, *tail = NULL;



node *makeNode(int a){
  node * p = (node *) malloc(sizeof(node));
  p->id = a;
  p->next = NULL;
  p->prev = NULL;

  return p;
}

node * search(int a){
  node * p = head;
  do{
    p = p -> next;
  }while(p->id != a);

  return p;
}


void insertNode(int a, node *eye){
  node * p = makeNode(a);
  if(head == NULL) head = p;
  else{
    p -> next = eye -> next;
    p->prev = eye;
    if(eye -> next !=NULL) eye->next -> prev = p;
    eye -> next = p;
  }
}

void deleteNode(node *eye){
  if(head == NULL) return ;

  
  if( eye = head) head = head -> next;
  else eye -> prev -> next = eye -> next;

  
  if(eye -> next != NULL) eye -> next-> prev = eye -> prev;
  else tail = eye -> prev;

  free(eye);

}

void freeList(node *head){
  node *p = head;
  while(head != NULL){
    head = head->next;
    free(p);
    p = head;
  }

  free(p);
  free(head);
}

void viewList(node *head){
  node *p = head;
  while(p != NULL){
    printf("%d  ", p->id);
    p = p->next;
  }
  printf("\n");
  free(p);
}

int main(){
  for(int i = 0; i< 9; i++){
    insertNode(i, head);
  }
  viewList(head);
  node *temp = search(5);
  deleteNode(temp);
  viewList(head);
  
}
