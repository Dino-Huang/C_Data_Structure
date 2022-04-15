//print random 20 number unrepeatealbe into an array in the range of 0-500

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int min=0;
int max=10;
int number=10;

void PrintArr(int arr[number]){
    for(int i=0; i<number;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    //[200,100,300,n], check 0~[n-1], if repeat ,generate new one
    int arr[number];
    int tem = 0;
    int repeat= 0;
    srand(time(NULL));
    for ( int i = 0; i < number; i++ ){
        arr[i] = rand() % 10;
        repeat = 0;
        do{ 
            for (int j = 0; j < i; j++)
            {
                // number repeat
                if(arr[i] == arr[j])
                {
                    tem = rand() % 10;
                    arr[i] = tem;
                    repeat = 1;
                    break;
                }else// number is not repeat
                {
                    repeat = 0;
                } 
            }
        }while(repeat == 1);
    }
    PrintArr(arr);
    return 0;
}

