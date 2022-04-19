#include<stdio.h>

/*
Judge a given numer is power of 2?
*/

//methoed 1: find MSB and LSB of given number and check if they are the same value
int Find_MSB(unsigned int x)
{
    // make every bit after MSB = 1
    x|=x>>1;
    x|=x>>2;
    x|=x>>4;
    x|=x>>8;
    x|=x>>16;
    //clear all bit after MSB
    return x-(x>>1);
}

int Find_LSB(unsigned int x)
{
    x&=(-x);
    return Find_MSB(x);
}

char Is_power_of_2(unsigned int x)
{
    return Find_MSB(x) == Find_LSB(x)? 'Y':'N';
}

//methoed 2: check if x^=(x-1) greater than x or not
// its power of 2 if the condition is matched
// if a = 0010 0100, x-1 = 0010 0011
//        0010 0100
//      ^ 0010 0011
//------------------
//        0000 0111 this will be 0000 0111
#define IS_POWER_OF_2(x)(x < (x^(x-1))? 'Y':'N')

int main()
{
    // MSB = 64 LSB = 8
    unsigned int a = 0b01001000; 
    printf("MSB : %d\n",Find_MSB(a));
    printf("LSB : %d\n",Find_LSB(a));
    printf("The given number is power of 2(M1) :%c\n",Is_power_of_2(a));
    printf("The given number is power of 2(M2) :%c\n",IS_POWER_OF_2(a));
    return 0;
}