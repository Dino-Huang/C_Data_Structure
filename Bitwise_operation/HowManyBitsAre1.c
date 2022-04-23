#include<stdio.h>
#include<stdlib.h>

/*
給一個32bit數值,請計算有幾個bit是1?
ex: 1000 1100 => 3 bit are 1
*/

void FindSetBit_M1(unsigned int x)
{
    int count ;
    for(int i=0;i<8;i++)
    {
        if((x & (1<<i)) != 0)
        {
            count++;
        }
    }
    printf("There are %d bits are 1 !\n",count);
}

void FindSetBit_M2(unsigned int x)
{
    int count = 0;
    while(x!=0)
    {
        x &= (x-1);
        count++;
    }
    printf("There are %d bits are 1 !\n",count);
}

int main()
{
    unsigned int x = 0b10001100;//x = 25
    FindSetBit_M1(x);
    FindSetBit_M2(x);
    return 0;
}