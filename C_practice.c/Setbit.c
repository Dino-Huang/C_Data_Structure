#include<stdio.h>
#include<stdlib.h>

#define Bit1 (0x0001) //0001
#define Bit2 (0x0002) //0010
#define Bit3 (0x0004) //0100
#define Bit4 (0x0008) //1000
#define Bit5 (0x0005) //0101
#define Bit6 (0x0006) //0110
#define Bit7 (0x0007) //0111
#define Bit8 (0x0008) //1000



int set3bit(int a){return(a|= Bit4);} 


int main(){
    //given a number of unsignedint 32 bit 0x00000008, set 3 bit = 1 
    //0x = 16, 0100(2) = 2^2 = 4 => 0x0004(16)
    //set 3 bit =1 -> 0 => 1  or 
    //0000 1000 = > 0000 1100 
    //0000 0100 = 8
    //0000 1100 = 12
    
    unsigned int temp = 0x00000001; // 0001
    printf("%d\n",temp);
    temp = set3bit(temp);
    printf("%d\n",temp); //1001
}