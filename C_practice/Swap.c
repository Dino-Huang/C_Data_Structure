#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
swap a and b using bitwise operation without external variables
if a = 0010 (2)
   b = 0101 (5)
a ^ 0 = a
a ^ a = 0
a ^ b = b ^ a
a = a ^ b
b = a ^ b = a ^ b ^ b = a
a = a ^ b = a ^ b ^ a = b
*/

void swap(int *a , int *b)
{
    *a = (*a)^(*b);
    *b = (*b)^(*a);
    *a = (*a)^(*b);
}

int main()
{
    int *a,*b;
    int j = 1,k=2;
    a=&j;
    b=&k;
    printf("a : %d, b : %d\n",*a,*b);
    swap(a,b);
    printf("a : %d, b : %d\n",*a,*b);
    return 0;
}