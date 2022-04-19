#include<stdio.h>
#include<stdlib.h>

/*
Q1. given a 8 bits value, find highest order 
bit(MSB // Most Significant Bit)
*/
//char 1 byte 4 bits 
//unsigned char 2 byte 8 bits 
//if ask MSB then return binary
int Find_MSB(unsigned char x)
{
    if(x == 0b00000000) return -1;
    x |= (x>>1);
    x |= (x>>2);
    x |= (x>>4);

    return x-(x>>1);
}

/*
Q2. given a 8 bits value, find position of highest
order bit(MSB // Most Significant Bit)
*/
//if ask MSB position then return pos(int)
int Find_MSB_position(unsigned char value){
    int n = 7;
    if(value == 0b00000000) return -1;
    if(value >> 4 == 0) {n=n-4;value = value<<4;}
    if(value >> 6 == 0) {n=n-2;value = value<<2;}
    if(value >> 7 == 0) {n=n-1;value = value<<1;}

    return n;
}

/*
Q3. given a 8 bits value , find least order 
bit(LSB // Least Significant Bit)
*/
// tips : do value&(-value) then find MSB
// -x(minus) = ~x + 1 
// if given is 0001 0001, ~x = -(x + 1) = - 0001 0010 
int Find_LSB(unsigned char value){
    return value &= (-value);
}

int Find_LSB_position(unsigned char value){
    value &= (-value);
    return Find_MSB_position(value);
}


int main()
{
    
    unsigned char number = 0b00001000;// 8
    printf("input = %hhu(in binary)\n",number);
    printf("MSB pos : %d\n",Find_MSB_position(number));
    printf("MSB : %d\n",Find_MSB(number));

    unsigned char number2 = 0b00001110;// 14
    printf("input2 = %hhu(in binary)\n",number2);
    printf("LSB : %d\n",Find_LSB(number2));
    printf("LSB pos : %d\n",Find_LSB_position(number2));
    return 0;
}