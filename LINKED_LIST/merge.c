#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

void create(struct ListNode**);    //Function to create a linkedlist
void print(struct ListNode*);      //Function to print the linkedlist
struct ListNode* merge(struct ListNode*,struct ListNode*);   //Function to merge two sorted linkedlist

int main(){
   printf("The Input LinkedList must be sorted in non-decreasing order.\n");
   struct ListNode* head1=(struct ListNode*)malloc(sizeof(struct ListNode));
   printf("Enter the value of first node of first linkedlist: ");
   scanf("%d",&head1->val);
   create(&head1);
   struct ListNode* head2=(struct ListNode*)malloc(sizeof(struct ListNode));
   printf("Enter the value of first node of second linkedlist: ");
   scanf("%d",&head2->val);
   create(&head2);
   print(head1);
   print(head2);
   struct ListNode* list=merge(head1,head2);
   print(list);

   return 0;
}

void create(struct ListNode **temp){
    printf("Press 1 to create another node:\nPress 0 to end the linkedlist:\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1){
        (*temp)->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter the value of the node: ");
        scanf("%d",&(*temp)->next->val);
        create(&(*temp)->next);
    }
    else if(flag==0){
        (*temp)->next=NULL;
        printf("END of LinkedList.\n");
    }
    else{
        printf("Invalid Input!!\n");
    }

}

void print(struct ListNode* temp){
    if(temp==NULL){
        printf("NULL\n");
        return;
    }
    while(temp->next!=NULL){
        printf("%d -> ",temp->val);
        temp=temp->next;
    }
    printf("%d\n",temp->val);
}

struct ListNode* merge(struct ListNode* list1,struct ListNode* list2){
    if(list1==NULL&&list2==NULL){
        return NULL;
    }
    struct ListNode* list=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ll=list;
    while(list1!=NULL&&list2!=NULL){
        if(list1->val<list2->val){
            list->val=list1->val;
            list1=list1->next;
            list->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            list=list->next;
        }
        else{
            list->val=list2->val;
            list2=list2->next;
            list->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            list=list->next;
        }
    }
    if(list2==NULL){
        while(list1->next!=NULL){
            list->val=list1->val;
            list1=list1->next;
            list->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            list=list->next;
        }
        list->val=list1->val;
        list->next=NULL;
    }
    else{
        while(list2->next!=NULL){
            list->val=list2->val;
            list2=list2->next;
            list->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            list=list->next;
        }
        list->val=list2->val;
        list->next=NULL;
    }
    return ll;
}
