#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* swapgroup(struct ListNode* head,int k){
    struct ListNode *temp,*list=head;
    int i,j,group=0;
    while(head!=NULL){
        group++;
        head=head->next;
    }
    group=group/k;
    head=list;
    int *arr=(int*)calloc(k,sizeof(int));
    for(i=1;i<=group;i++){
        temp=head;
        for(j=0;j<k;j++){
            *(arr+j)=head->val;
            head=head->next;
        }
        head=temp;
        for(j=k-1;j>=0;j--){
            head->val=*(arr+j);
            head=head->next;
        }
    }
    return list;
}

