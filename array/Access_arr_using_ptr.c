#include<stdio.h>

int main(){

    int size;
    printf("please enter the size of array : ");
    scanf("%d",&size);

    int arr[size];
    printf("please enter the element of array !\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Access array using pointer !\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("Element %d : ",i+1);
        printf("%d\n",*(arr+i));
    }
    return 0;
}