#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* sortList(struct ListNode*); //Function to sort the nodes of a linkedlist

int main(){

  return 0;
}

//NOTE: This function sort the nodes of the linkedlist, not the value of the nodes of a linkedlist.
//BUBBLE SORT OF LINKEDLIST
struct ListNode* sortList(struct ListNode* head){
    struct ListNode *ptr1=head,*ptr2=head->next,*previous;
    int i,j,count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    head=ptr1;
    for(i=1;i<count;i++){
        for(j=1;j<=count-i;j++){
           if(ptr1->val>ptr2->val){
               ptr1->next=ptr2->next;
               ptr2->next=ptr1;
               if(j==1){
                  head=ptr2;
                  previous=head; 
               }
               else{
               previous->next=ptr2;
               previous=ptr2;
               }
               ptr2=ptr1->next;
           }
           else{
               previous=ptr1;
               ptr1=ptr2;
               ptr2=ptr1->next;
           }
        }
        ptr1=head;
        ptr2=head->next;
    }
    return head;
}
