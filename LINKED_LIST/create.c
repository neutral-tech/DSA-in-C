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

int main(){
    node *head=(node*)malloc(sizeof(node));
    create(head);
    printf("\n");
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
