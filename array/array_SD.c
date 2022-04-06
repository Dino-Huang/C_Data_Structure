#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float calculate_SD(float arr[],int arr_size){
    float mean;
    for (int i = 0; i < arr_size; ++i)
    {
        mean+=arr[i];
    }
    mean=mean/(float)arr_size;
    printf("Mean : %.2f\n",mean);

    float sigma=0.0;
    for (size_t i = 0; i < arr_size; ++i)
    {
        sigma+=pow(arr[i]-mean,2);
    }
    
    return sqrt(sigma/arr_size);
}

int main(){
    float *arr;
    int arr_size=10;
    arr=(float*)malloc(arr_size*sizeof(float));
    printf("please enter %d element into array!\n",arr_size);
    for (int i = 0; i < arr_size; ++i)
    {
        printf("Element%d:",i+1);
        scanf("%f",&arr[i]);
    }
    
    float SD=0.0;
    SD = calculate_SD(arr,arr_size);
    printf("Standard deviation is %.5f\n",SD);

    //free memory
    free(arr);
    return 0;
}