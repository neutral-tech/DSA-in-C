#include<stdio.h>
#include<stdlib.h>

//Definition of a node.
//Self-referential structure.
struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist node;

void create(node**);           //Function to create a linked list
void print(node*);             //Function to print the linked list
void count(node*);             //Function to count the number of nodes in linked list
void insertFirst(node**);      //Function to insert a node at the beginning of linked list
void insertLast(node*);        //Function to insert a node at the end of linked list
void sum(node*);               //Function to print the sum of data of all the nodes
void operate(node**);          //Function to do operations on linkedlist

int main(){
    node *head=(node*)malloc(sizeof(node));
    printf("Enter the value of the first node: ");
    scanf("%d",&head->data);
    operate(&head);

   return 0;
}

void create(node **temp){     //temp is a pointer to the pointer head.
    printf("Press 1 to create another node.\nPress 0 to end the linkedlist.\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1){
        (*temp)->next=(node*)malloc(sizeof(node));
        printf("Enter the value of the node: ");
        scanf("%d",&(*temp)->next->data);
        printf("\n");
        create(&(*temp)->next);
    }
    else if(flag==0){
        (*temp)->next=NULL;
        printf("End of linkedlist.\n");
    }
    else printf("Invalid Input\n");
}

void print(node *temp){     //temp is a pointer to the first node just like head is.
     while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
     }
     if(temp->next==NULL){
        printf("%d\n",temp->data);
     }
}

void count(node *temp){     //temp is a pointer to the first node just like head is.
     int count=1;
     while(temp->next!=NULL){
        count++;
        temp=temp->next;
     }
     printf("Number of nodes = %d\n",count);
}

void insertFirst(node **temp){    //temp is a pointer to the pointer head.
     node *new=(node*)malloc(sizeof(node));
     printf("Enter the value of the new node: ");
     scanf("%d",&new->data);
     new->next=*temp;
     *temp=new;
     printf("Node insertion successful.\n");
}

void insertLast(node *temp){    //temp is a pointer to the first node just like head is.
      node *new=(node*)malloc(sizeof(node));
      printf("Enter the value of the new node: ");
      scanf("%d",&new->data);
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=new;
      new->next=NULL;
      printf("Node insertion successful.\n");
}

void sum(node *temp){            //temp is a pointer to the first node just like head is.
     int sum=0;
     while(temp->next!=NULL){
        sum+=temp->data;
        temp=temp->next;
     }
     sum=sum+temp->data;
     printf("Sum = %d\n",sum);
}

void operate(node **temp){      //temp is a pointer to the pointer head. It stores the address of the pointer which points to the first node.
    printf("\nOperations on linkedlist:\n\n1.Creation of Linked List\n2.Print the Linked List\n3.Count the number of nodes\n4.Insertion at the start\n5.Insertion at the last\n");
    printf("6.Sum of all the nodes\n7.End the program\n\nInput: ");
    int input;
    scanf("%d",&input);
    switch (input)
    {
    case 1: create(temp);
            operate(temp);
        break;
    
    case 2: print(*temp);
            operate(temp);
        break;

    case 3: count(*temp);
            operate(temp);
        break;
    
    case 4: insertFirst(temp);
            operate(temp);
        break;
    
    case 5: insertLast(*temp);
            operate(temp);
        break;
    
    case 6: sum(*temp);
            operate(temp);
        break;
    
    case 7: return;
        break;
    
    default: printf("Invalid Request!!\n");
        operate(temp);
        break;
    }
}


