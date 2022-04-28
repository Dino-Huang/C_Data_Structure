#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
1.實作 SetBit/ClearBit/CheckBit/FlipBit
2.實作一函示能夠交換兩數字且不使用額外變數
3.尋找最高為元為1的值(MSB) 與最低位元為1的值(LSB)與其位於第幾個bit
4.給一個數值，求其有多少個bit為1?
5.給一個數值，求其是否為2的n次方
6.給你一個unsigned short(2bytes 16 bit)，問換算成16進制後四個值是不是一樣
，是回傳1，否則0 例如：0xFFFF return 1, 0xAAAB return 0
*/

#define Set_Bit(a,n) ( a |= (1<<n) )
#define ClearBit(a,n) (a &= (~(1<<n)))
#define CheckBit(a,n) ((a&(1<<n)? 'Y':'N'))
#define FlipBit(a,n) ( a^=(1<<n)) //1^1 = 0 0 ^1=1
#define PrintBinary(a) \
    ( a & (1<<7) ? '1' : '0' ), \
    ( a & (1<<6) ? '1' : '0' ), \
    ( a & (1<<5) ? '1' : '0' ), \
    ( a & (1<<4) ? '1' : '0' ), \
    ( a & (1<<3) ? '1' : '0' ), \
    ( a & (1<<2) ? '1' : '0' ), \
    ( a & (1<<1) ? '1' : '0' ), \
    ( a & (1<<0) ? '1' : '0' )

int FindMSB(unsigned char n){
    if(n==0) return -1;
    n|=(n>>1);
    n|=(n>>2);
    n|=(n>>4);
    return n-(n>>1);
}

int FindMSB2(unsigned char n){
    int index =7;
    while((n&(1<<index))==0){
        index--;
    }
    return (1<<index);
}

int FindLSB(unsigned char n){
    return n&(-n);
}

void Swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;// b = a
    *a = *a ^ *b;//a = b
}

int NumOfBit(unsigned char x){
    int n = 0;
    for (int i = 7; i >=0; i--)
    {
        if( x&(1<<i) ){
            n++;
        }
    }
    return n;
}

char IsPowerof2(unsigned char x){
    if((x&(x-1))==0)
    {
        return 'Y';
    }else return 'N';
}

char hexadecimal(unsigned short int a)
{
    //if a = 0x1110 = 0001 0001 0001 0000 
    //using mask = first 4 bits or last 4 bits
    unsigned short mask = (a>>12);
    mask = mask+(mask<<4)+(mask<<8)+(mask<<12);
    if(a==mask) {
        return 'Y';
    }else{
        return 'N';
    }
}

char hexadecimal2(unsigned short int  a){
    if(((a^(unsigned short int)(a<<4)))>>4==0){
        return 'Y';
    }else{
        return 'N';
    }
}

char IsPrimeNumber(unsigned int a){
    if( a<2) return 'N';
    for (int i = 2; i<(a/2);i++)
    {
        if((a%i)==0)return 'N';
    }
    return 'Y';
}

int main()
{
    unsigned char a = 0b00000000;
    Set_Bit(a,1);
    printf("Binary : %c%c%c%c%c%c%c%c\n",PrintBinary(a));
    FlipBit(a,3);
    printf("Binary : %c%c%c%c%c%c%c%c\n",PrintBinary(a));
    printf("MSB : %d\n",FindMSB2(a));
    printf("LSB : %d\n",FindLSB(a));
    int x = 3, y=1;
    printf("x:%d y:%d\n",x,y);
    Swap(&x,&y);
    printf("x:%d y:%d\n",x,y);
    printf("Num : %d\n",NumOfBit(a));
    printf("a is power of 2 : %c\n",IsPowerof2(a));
    unsigned short int h = 0x1111;
    printf("hexademical of a is the same : %c\n",hexadecimal2(h));
    int num = 1;
    printf("Is %d a prime number : %c \n",num,IsPrimeNumber(num));
    return 0;
}

