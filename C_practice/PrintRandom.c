#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define arr_size 10

void PrintArr(int arr[arr_size])
{
    for (int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SortArr(int arr[]){
    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < i; j++){
            if( arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
        }
    }
}

void func(int arr[],int size){
    int *ptr = arr;
    for (int i = 0; i < 30; i++)
    {
        if(*ptr == i ){
            ptr++;
        }else{
            printf("%d ", i);
        }
        
    }
    
}
void PrintNotInArr(int a[]){
    int index = 0;
    for (int i = 0; i < 30; i++)
    {
        if(i == a[index])
        {
            index++;
        }else
        printf("%d ", i);{}
    }
    
    
}

int main(){
    int arr[arr_size];
    srand(time(NULL));
    //generate random numbers in array
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = rand() % 30;
        for (int j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                arr[i] = rand () % 30;
                j = -1;
            }
        }
        
    }
    printf("Origin : \n");
    PrintArr(arr);
    SortArr(arr);
    printf("Sorted : \n");
    PrintArr(arr);    
    printf("Random number not in array : \n");
    //PrintNotInArr(arr);
    func(arr,5);
    //PrintArr(arr);
    

}