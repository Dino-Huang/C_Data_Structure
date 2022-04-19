#include<stdio.h>
/*
Q2: 給一個int a[20]已排序的陣列，請寫一個function(a, size, b)
能依照參數b(b = 0~4)別印出該區間的數字，且不包含a陣列內的元素，例如：
b = 0 , print 0~99
b = 1 , print 100~199
*/

void function(int *a,int size, int b){
    int *ptr = a;
    int i;

    //shift start ptr based on b 
    while(*ptr < b*100)
    {
        ptr++;
    }

    for (i=b*100; i<(b+1)*100; i++)
    {
        if(*ptr == i)
        {
            ptr++;
        }else
        {
            printf("%d ",i);
        }
    }
}

int main()
{
    int a[5]={1,5,7,107,109};//sorted array
    function(a,5,1);
    return 0;
}