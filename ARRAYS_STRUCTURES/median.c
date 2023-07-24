#include<stdio.h>
#include<stdlib.h>

void create(int**,int m);                //Function to create an array
double findMedian(int*,int,int*,int);        //Function to sort two sorted arrays in a new array and return the median of it
void print(int*,int);                    //Function to print the array
int main(){
   int *arr1,*arr2,m,n;
   printf("Enter the size of first array: ");
   scanf("%d",&m);
   create(&arr1,m);
   printf("Enter the size of second array: ");
   scanf("%d",&n);
   create(&arr2,n);
   print(arr1,m);
   print(arr2,n);
   double median=findMedian(arr1,m,arr2,n);
   printf("\nMedian = %lf\n",median);
  

   return 0;
}

void create(int** temp,int size){                     //temp is a pointer which stores the address of the array pointer or the address of the
  int i=0;                                            //first element of the array
  *temp=(int*)calloc(size,sizeof(int));
  printf("Enter the elements:\n");
  while(i<size){
    scanf("%d",*temp+(i++));
  }
  printf("\n");
}

void print(int* arr,int size){
   int i=0;
   while(i<size){
    printf("%d  ",*(arr+(i++)));
   }
   printf("\n");
}

double findMedian(int* nums1,int nums1Size,int* nums2,int nums2Size){
    int i=0,j=0,k=0;
    double median;
    int* arr=(int*)calloc((nums1Size+nums2Size),sizeof(int));
    while(i<nums1Size&&j<nums2Size){
        if(*(nums1+i)<*(nums2+j)){
            *(arr+(k++))=*(nums1+(i++));
        }
        else{
            *(arr+(k++))=*(nums2+(j++));
        }
    }
    if(j==nums2Size){
        while(i<nums1Size){
            *(arr+(k++))=*(nums1+(i++));
        }
    }
    else{
        while(j<nums2Size){
            *(arr+(k++))=*(nums2+(j++));
        }
    }
    int index=(nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2==1){
        median=(double)(*(arr+index));
    }
    else{
        median=((double)(*(arr+index))+(*(arr+index-1)))/2;
    }
    return median;
}
