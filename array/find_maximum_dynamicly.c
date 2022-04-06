#include<stdio.h>
#include<stdlib.h>

int main(){
    int size;
    printf("please enter the number of elements : ");
    scanf("%d",&size);

    //memory allocation
    double *data;
    data=(double*)calloc(size,sizeof(double));
    if(data==NULL)
    {
        printf("Memory allocation failed!\n");
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("please enter element %d :",i+1);
        scanf("%lf",data+i);
    }

    //find maximum in data
    for (size_t i = 0; i < size; i++)
    {
        printf("%.2lf\n",*(data+i));
        if(*(data+i)>*data)
        {
            *data=*(data+i);
        }
    }
    printf("Maximum : %.2lf\n",*data);

    free(data);
    return 0;
}

