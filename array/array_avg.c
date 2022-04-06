#include<stdio.h>

int main(){
    int n;
    float arr[10],sum=0.0,avg;

    printf("please enter the size of array : ");
    scanf("%d",&n);

    if (n>10||n<1)
    {
        /* code */
        printf("input number is out of range!");
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        printf("Element %d : ",i+1);
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    
    avg=sum/n;
    printf("Average is %.2f \n",avg);

    return 0;
}