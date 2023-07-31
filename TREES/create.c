#include<stdio.h>
#include<stdlib.h>
struct node{
   int value;
   struct node* leftchild;
   struct node* rightchild;
};
typedef struct node node;
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

void create(node*);    //Function to create a binary tree in a preorder traversal way.
void inorder(node*);   //Function to traverse a binary tree in an inorder way.
void preorder(node*);  //Function to traverse a binary tree in a preorder way.
void postorder(node*); //Function to traverse a binary tree in a postorder way.

int main(){
   node* root=(node*)malloc(sizeof(node));
   printf("Enter the value of root: ");
   scanf("%d",&root->value);
   create(root);
   printf("\nINORDER TRAVERSAL: ");
   inorder(root);
   printf("\nPREORDER TRAVERSAL: ");
   preorder(root);
   printf("\nPOSTORDER TRAVERSAL: ");
   postorder(root);
   printf("\n");
   return 0;   
}

//This function creates a binary tree in a preorder traversal way.
void create(node* root){
   if(root==NULL){
      return;
   }
   printf("Enter the value of left child of %d : ",root->value);
   int val;
   scanf("%d",&val);
   if(val==-1){
      root->leftchild=NULL;
   }
   else{
   root->leftchild=(node*)malloc(sizeof(node));
   root->leftchild->value=val;
   create(root->leftchild);
   }
   printf("Enter the value of right child of %d : ",root->value);
   scanf("%d",&val);
   if(val==-1){
      root->rightchild=NULL;
   }
   else{
   root->rightchild=(node*)malloc(sizeof(node));
   root->rightchild->value=val;
   create(root->rightchild);
   }

   return;
}

void inorder(node* root){
   if(root==NULL){
      return;
   }
   inorder(root->leftchild);
   printf("%d ",root->value);
   inorder(root->rightchild);
}

void preorder(node* root){
   if(root==NULL){
      return;
   }
   printf("%d ",root->value);
   preorder(root->leftchild);
   preorder(root->rightchild);
}

void postorder(node* root){
   if(root==NULL){
      return;
   }
   postorder(root->leftchild);
   postorder(root->rightchild);
   printf("%d ",root->value);
}