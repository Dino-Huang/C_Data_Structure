#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b ;
    *b = temp;
}

void PrintArr(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void Quicksort(int arr[],int left, int right) {
    printf("left %d right %d\n",left,right);
    if (left >= right) {return;}
    
    int pivot = arr[left];
    int i = right;//5
    int j = left;//0

    while(i!=j)
    {
        while(arr[i]>= pivot && i > j) {i --;}
        while(arr[j]<= pivot && j < i) {j ++;}
        if(i>j){swap(&arr[i],&arr[j]);}
    }
    
    arr[left] =arr[i];
    arr[i] = pivot;
    
    Quicksort(arr,left,i-1);
    Quicksort(arr,i+1,right);
}    

void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;
   
   if(first<=last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

int main()
{
    int arr[] = {3,2,1,4,5,6};
    int left = 0;
    int right = 5;
    
    int size = sizeof(arr)/sizeof(int);
    PrintArr(arr,size);
    printf("\n");
    Quicksort(arr,left,right);
    printf("\n");
    PrintArr(arr,size);
    quicksort(arr,left,right);
    printf("\n");
    PrintArr(arr,size);

    return 0;
}