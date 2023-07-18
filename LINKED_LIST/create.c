#include<stdio.h>
#include<stdlib.h>


//Definition of node
//Self-referential structure

 struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist node;

void create(node*);//Function to create a linkedlist
void print(node*);//Function to print the linkedlist
int count(node*);//Function to count the number of nodes in linkedlist
node* insertFirst(node*,int);//Function to insert a node in the beginning of linkedlist

int main(){
    node *head=(node*)malloc(sizeof(node));
    create(head);
    printf("\n");
    print(head);
    printf("\nNumber of nodes: %d\n",count(head));
    printf("\nEnter the value to insert at the beginning: ");
    int a;
    scanf("%d",&a);
    head=insertFirst(head,a);
    printf("\nAfter insertion:\n");
    print(head);
    printf("\nNumber of nodes: %d\n",count(head));

   return 0;
}

void create(node *temp){
    printf("Enter the data:\n(Type -101 to END)\n");
    scanf("%d",&temp->data);
    if(temp->data!=-101){
        temp->next=(node*)malloc(sizeof(node));
        create(temp->next);
    }
    else{
        temp->next=NULL;
    }
}

void print(node *temp){
    if(temp->next->next!=NULL){
        printf("%d ->-> ",temp->data);
        print(temp->next);
    }
    else{
        printf("%d\n",temp->data);
    }
}

int count(node *temp){
    int count=0;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

node* insertFirst(node *temp,int value){
     node *sth=(node*)malloc(sizeof(node));
     sth->data=value;
     sth->next=temp;
     temp=sth;
     return temp;
}
