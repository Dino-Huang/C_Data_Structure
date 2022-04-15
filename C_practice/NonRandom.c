#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Generate an array target[0,1,2,3,4,5,6,7,8,9]
//generate a number i as position in array
//arr[k] = target[i], then set target[i] = -1
//keep going when target[i] == -1 then generate anoter number as position

#define arr_size 10
#define IsUsed -1
#define UnAssign -2


void PrintArray(int arr[arr_size]){
    printf("[");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}


int main(){

    int target[arr_size];
    int arr[arr_size]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};

    for (int i = 0; i < arr_size; i++)
    {
        target[i]=i;
    }
    
    for (int i = 0; i < arr_size; i++)
    {
        srand(time(NULL));
        int rand_num = rand() % 10;//generate random number within 0 - 9
        if (target[rand_num]!= (-1))
        {
            arr[i]=target[rand_num];
            target[rand_num] = IsUsed;
        }
        else // if the number has been taken
        {
            while (arr[i]== UnAssign)
            {
                rand_num = rand() % 10;//generate random number within 0 - 9 
                if(target[rand_num]!= (IsUsed))//until find the element havent been used
                {   
                    arr[i] = target[rand_num];
                    target[rand_num] = IsUsed;
                }
            }
        }
    }
    PrintArray(arr);  
}



