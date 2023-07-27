#include<stdio.h>
#include<stdlib.h>

int* create(int*,int);
void print(int*,int);
int* sort(int*,int);

int main(){
    printf("Enter the size of array: ");
    int size;
    scanf("%d",&size);
    int *nums=(int*)malloc(size*sizeof(int));
    nums=create(nums,size);
    printf("Unsorted Array:\n");
    print(nums,size);
    nums=sort(nums,size);
    printf("Sorted Array:\n");
    print(nums,size);
    return 0;
}

int* create(int *nums,int size){
   if(size==0){
    return nums;
   }
   int i;
   printf("Enter the elements:\n");
   for(i=0;i<size;i++){
    scanf("%d",(nums+i));
   }
   printf("\n");
   return nums;
}

void print(int* nums,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",*(nums+i));
    }
    printf("\n");
}

//BUBBLE SORT
int* sort(int* nums,int size){
    int i,j,k;
    for(i=1;i<size;i++){
        for(j=0;j<size-i;j++){
            if(*(nums+j)>*(nums+j+1)){
               *(nums+j)=*(nums+j)+*(nums+j+1);
               *(nums+j+1)=*(nums+j)-*(nums+j+1);
               *(nums+j)=*(nums+j)-*(nums+j+1);
            } 
        }
    }
    return nums;
}