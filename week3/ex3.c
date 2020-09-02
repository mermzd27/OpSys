#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}node;

node * generate(int numberOfNodes);
void print_list(node * head);
node * deleteIfHead(node * head, int newNumber);
void  insert_node(int newNumber, int position, node **head);
void delete_node(node **head, int numberToDelete);

int main()

{
    
    int numberOfNodes=0;
    int postionForInsertion;
    node * HEAD=NULL;
    int numberToInsert;
    int numberToDelete;


    printf("enter the number of nodes for you linked list\n");
    scanf("%d", &numberOfNodes);
    HEAD = generate(numberOfNodes);
    print_list(HEAD);
   
    /*printf("\nChoose element after which to insert (from 1 to %d)",numberOfNodes);
    scanf("%d", &postionForInsertion);
    if(postionForInsertion>numberOfNodes||postionForInsertion<0) {
            printf("you entered incorrect postion, check again, please\n");
    }
    if(postionForInsertion==0){
    HEAD=deleteIfHead(HEAD, 6);
    print(HEAD);
    }*/
    
    printf("\nenter one number to insert\n");
    scanf("%d", &numberToInsert);
    printf("\nenter position to insert (from 1 to %d)",numberOfNodes+1);
    scanf("%d", &postionForInsertion);
    insert_node(numberToInsert, postionForInsertion, &HEAD);
    print_list(HEAD);
    
    printf("\nenter one number to delete from list\n");
    scanf("%d", &numberToDelete);
    delete_node(&HEAD,numberToDelete);
    print_list(HEAD);

    
    return 0;
}

node * generate(int numberOfNodes){
    int i=0;
    node * head = NULL;
    node * temp=NULL;
    node * p=NULL;

    
    for (i=0; i<numberOfNodes; i++){
        temp = (node*)malloc(1*sizeof(node));
        
    
        printf("\nenter the element of your linked list at position %d ", i+1);
        scanf("%d", &(temp->data));
        temp->next=NULL;
    
        if(head==NULL){
            head=temp;
        }else{
            p=head;
        
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=temp;
        }
    }
    
    return head;
}


void print_list (node * head) {
    printf("\n");
    node * p = head;
    while(p!=NULL) {
        printf("%d->",p->data);
        p=p->next;
    }
    
}

node * deleteIfHead(node * head, int newNumber){
    node * newNode=NULL;

    newNode=(node*)malloc(sizeof(node));
    newNode->data=newNumber;
    newNode->next=head;
    head=newNode;
    
    return(newNode);
    
}


void delete_node(node ** head, int numberToDelete) 
{ 
    node* temp = *head, *prev; 
      if (temp != NULL && temp->data == numberToDelete) 
    { 
        *head = temp->next;   
        free(temp);             
        return; 
    } 
    while (temp != NULL && temp->data != numberToDelete) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);  
} 

void insert_node(int newNumber, int position, node **head){
    node * q1=NULL;

    q1 = (node*)malloc(1*sizeof(node));
    q1->data=newNumber;
    q1->next=NULL;
           
    if(position==1){
        q1->next=*head;
        *head=q1;
        return;
    }
            
    node*q2=*head;
    for(int i=0; i<position-2;i++){
        q2=q2->next;
    }
    q1->next=q2->next;
    q2->next=q1;
            
            
}

















