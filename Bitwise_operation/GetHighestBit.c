#include<stdio.h>
#include<stdlib.h>

int getHeighestBitPosition(unsigned char x)
{
    if (x == 0b00000000)
    {
        return -1;
    }
    int n =7;
    if((x>>4) == 0) {n = n-4; x = x<<4;}
    if((x>>6) == 0) {n = n-2; x = x<<2;}
    if((x>>7) == 0) {n = n-1;}
    return n;
}

int setBitNumber(int n)
{
    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;

    n+=1;

    return n>>1;
}

unsigned hibit(unsigned n) {
    n |= (n >>  1u);
    n |= (n >>  2u);
    n |= (n >>  4u);
    n |= (n >>  8u);
    n |= (n >> 16u);
    return n - (n >> 1);
}

int main(){
    unsigned char a = 0b00000010;//2
    //printf("%hhu\n",a);
    printf("MSB at position %d!\n",getHeighestBitPosition(a));
    //printf("%d\n",setBitNumber(12));
    printf("%u\n",hibit(12));
    printf("%d\n",1<<3);
    
}