#include<stdio.h>

int main(){
    int n;
    float arr[10];

    printf("please enter the size of array : ");
    scanf("%d",&n);

    if (n>10||n<1)
    {
        printf("n is out of range!\n");
        return 0;
    }
    
    for (int i = 0; i < n; ++i)
    {
        printf("Element %d :",i+1);
        scanf("%f",&arr[i]);
        if(arr[i]>arr[0]){
            arr[0]=arr[i];
        }
    }
    printf("Maximum in array is %.2f\n",*arr);
    
    return 0;
}