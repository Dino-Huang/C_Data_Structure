#include<stdio.h>
#include<stdlib.h>

// 1<<n this operation means masking
// &0 force specific bit to 0
// |1 force specific bit to 1


#define True 1
#define False 0
// byte to binary
// byte & 1<<n to check whether 1 or not
// if bit set return '1', otherwise return '0'
#define BYTE_TO_BINARY(byte) \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

//bit position from 0 start
// if x = 8 => 0000 1000
// set 1 bit = 1 
// | 0000 0001 << 1 = 0000 0010
#define SET_Bit( x , n) (x |= (1<<n)) 
// if x = 24 => 0001 1000
// clear 3 bit = 0 
// & ~(0000 0001 << 3) => ~(0000 1000)
// 0001 1000 & 1111 0111 = 0001 0000
#define CLEAR_Bit(x,n) (x &= (~(1 << n)))
// if x = 6 => 0000 0110
// check 2 bit = 0 or 1
// & (0000 0001 << 2) => 0000 0100
// 0000 0110 & 0000 0100 = 0000 0100 != 0
#define CHECK_Bit(x,n) ((x &= (1 << n)) != 0)
// if x = 8 => 0000 1000
// reverse 3 bit = 0000 1000 
//               ^ 0000 1000
//--------------------------
//               = 0000 0000
//  => 0000 0000
#define FLIP_Bit(x,n) ((x) ^=(1<<(n)))
// if x = 8 => 00001000
// flip all => 11110111
#define UPSIDEDOWN_ALL(x) ((~x))

int main()
{
    int a = 10;// 0b mean in binary
    printf("Set bit(%d) = %d\n",2,SET_Bit(a,2));
    printf("Clear bit(%d) = %d\n",3,CLEAR_Bit(a,3));
    printf("To Binary : %c%c%c%c%c%c%c%c\n",BYTE_TO_BINARY(a));
    int b = 1;
    printf("check bit(%d) : %d\n",2,CHECK_Bit(b,2));
    int c = 8;
    printf("To Binary : %c%c%c%c%c%c%c%c\n",BYTE_TO_BINARY(c));
    c = UPSIDEDOWN_ALL(c);
    printf("Upsidesown and to Binary : %c%c%c%c%c%c%c%c\n",BYTE_TO_BINARY(c));
    int d = 6;
    printf("flip bit(%d) : %d \n",2,FLIP_Bit(d,2));
    
    return 0;
}