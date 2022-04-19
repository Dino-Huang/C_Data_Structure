#include<stdio.h>
#include<stdlib.h>

#define Bit0 (0x0001) //0001
#define Bit1 (0x0002) //0001
#define Bit2 (0x0004) //0010
#define Bit3 (0x0008) //0100
#define Bit4 (0x0010) //0001 0000
#define Bit5 (0x0026) //0010 0000
#define Bit6 (0x0040) //0100 0000
#define Bit7 (0x0080) //1000 0000




int set3bit(int a){return(a|= Bit3);}
int set0bit(int a){return(a|= Bit0);} 


int main(){
    //given a number of unsignedint 32 bit 0x00000008, set 3 bit = 1 
    //0x = 16, 0100(2) = 2^2 = 4 => 0x0004(16)
    //set 3 bit =1 -> 0 => 1  or 
    //0000 1000 = > 0000 1100 
    //0000 0100 = 8
    //0000 1100 = 12
    
    unsigned int temp = 0x00000000; // 0000
    printf("%d\n",temp);
    temp = set3bit(temp);
    printf("%d\n",temp); //1000
    temp = set0bit(temp);
    printf("%d\n",temp); //1001
}