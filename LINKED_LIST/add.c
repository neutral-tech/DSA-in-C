#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode node;

void create(node**);
void print(node*);
struct ListNode* addTwoNumbers(struct ListNode*,struct ListNode*);

int main(){
    node *head=(node*)malloc(sizeof(node));
    printf("Creation of first linkedlist:\n");
    printf("Enter the value of first node: ");
    scanf("%d",&head->val);
    create(&head);
    printf("Creation of second linkedlist:\n");
    printf("Enter the value of first node of second linkedlist: ");
    node *h=(node*)malloc(sizeof(node));
    scanf("%d",&h->val);
    create(&h);
    print(head);
    print(h);
    node *add=addTwoNumbers(head,h);
    print(add);

    return 0;
}

void create(node **temp){
    printf("Press 1 to create another node:\nPress 0 to end the linkedlist:\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1){
        (*temp)->next=(node*)malloc(sizeof(node));
        printf("Enter the value of node: ");
        scanf("%d",&(*temp)->next->val);
        printf("\n");
        create(&(*temp)->next);
    }
    else{
        (*temp)->next=NULL;
        printf("End of linked list.\n");
    }
}

void print(node *temp){
    while(temp->next!=NULL){
        printf("%d -> ",temp->val);
        temp=temp->next;
    }
    printf("%d\n",temp->val);
}

struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){
    struct ListNode *first=l1,*second=l2;
    int sum=0,carry=0;
    while(first->next!=NULL&&second->next!=NULL){
        sum=first->val+second->val+carry;
        second->val=sum%10;
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    sum=first->val+second->val+carry;
    second->val=sum%10;
    carry=sum/10;

    if(first->next==NULL){
        if(carry==0){
           return l2; 
        }
        else if(second->next==NULL){
            second->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            second->next->val=carry;
            second->next->next=NULL;
        }
        else{
            second=second->next;
            while(second->next!=NULL){
                sum=second->val+carry;
                second->val=sum%10;
                carry=sum/10;
                if(carry==0){
                    break;
                }
                second=second->next;
            }
            
            if(second->next==NULL){
                sum=second->val+carry;
                second->val=sum%10;
                carry=sum/10;
                if(carry==0){
                    return l2;
                }
                else {
                second->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                second->next->val=carry;
                second->next->next=NULL;
                }
            }
        }
        return l2;

    }

    else {
        first=l1;second=l2;
        while(second->next!=NULL){
            first->val=second->val;
            first=first->next;
            second=second->next;
        }
        first->val=second->val;
        first=first->next;
        if(carry==0){
            return l1;   
        }
        
        else{
            while(first->next!=NULL){
                sum=first->val+carry;
                first->val=sum%10;
                carry=sum/10;
                if(carry==0){
                    break;
                }
                first=first->next;
            }
            if(first->next==NULL){
                sum=first->val+carry;
                first->val=sum%10;
                carry=sum/10;
                if(carry==0){
                    return l1;
                }
                first->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                first->next->val=carry;
                first->next->next=NULL;
            }
        }
        return l1;
    }   
}