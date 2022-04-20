#include <stdio.h>
#include <stdlib.h>

/*
給你一個unsigned short(2bytes 16 bit)，問換算成16進制後四個值是不是一樣，
是回傳1，否則0 例如：0xFFFF return 1, 0xAAAB return 0
*/

// bitwise operation in hexadecimal 
// a & b = a
// a | b = b


/*
Method 1 = numer divide by 16 4 times to check 
whether the remainders(餘數) are the same
*/
char DivideBy16(unsigned short a)
{
    printf("Remainders of 1th digit : %d\n",a%16);
    printf("Remainders of 2th digit : %d\n",(a/16)%16);
    printf("Remainders of 3rd digit : %d\n",(a/16/16)%16);
    printf("Remainders of 4th digit : %d\n",(a/16/16/16)%16);
    //check remainders
    if( a%16 == (a/16)%16 && // if 1th digit = 2th digit
        (a/16)%16== (a/16/16)%16 && // if 2th digit = 3th digit
        (a/16/16)%16 == (a/16/16/16)%16)// if 3th digit = 4th digit
    { 
        return 'Y';
    }
    return 'N';
}

/*
Method 2 = bitwise operation method
a^ (a<<4) it means that compare 1th to 2th digit,
2th to 3rd digit,3rd to 4th digit,the binary will be 0000 
if they are the same 
ex: if a = 0x1111 = 0001 0001 0001 0001
    a<<4 = 0x1110 = 0001 0001 0001 0000
    a ^ (a<<4) =    0000 0000 0000 0001 (first 3 parts are compare part)
    0000 0000 0000 0001 >>4 = 0000 0000 0000 0000 it means 4 digits are the same
*/
char Bitwise_method(unsigned short a)
{
    if ((a^((unsigned short)(a<<4))>>4)==0) return 'Y';
    else return 'N';
}

char Mask(unsigned short a)
{
    unsigned short mask = a>>12;
    mask += ((mask<<4)+(mask<<8)+(mask<<12));
    printf("%x\n",mask);
    return mask == a ? 'Y' : 'N';
}

int main(){
    unsigned short a = 0xAAfB;//0x1111
    unsigned short b = 0x000B;
    if ((a&b) == 0x000B)
    {
        printf("a & b = a\n");
    }
    printf("a = 0X%08x\n",(a));
    printf("a<<4 = 0X%08x\n",(a<<4));
    printf("a>>4 = 0X%08x\n",(a>>4));
    printf("a = %d\n",(a));
    printf("a<<4 = %d\n",(a<<4));
    printf("a>>4 = %d\n",(a>>4));
    printf("b = 0X%02x\n",(b));
    printf("a&b = 0X%02x\n",(a&b));
    printf("a|b = 0X%02x\n",(a|b));
    printf("a^b = 0X%02x\n",(a^b));
    
    printf("The last 4 digits are the same(M1)? %c\n",DivideBy16(a));
    printf("The last 4 digits are the same(M2)? %c\n",Bitwise_method(a));
    printf("The last 4 digits are the same(M3)? %c\n",Mask(a));
    unsigned short int n = 0b0001000100010001;
    unsigned short int m = n<<4;
    printf("%d\n",m^n);
    printf("%d\n",(m^n)>>4);


    return 0;
}