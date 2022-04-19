#include<stdio.h>

/*
In arithmetic-logic unit (which is within the CPU), mathematical 
operations like: addition, subtraction, multiplication and division 
are done in bit-level. To perform bit-level operations in C programming, 
bitwise operators are used.

 --------------------------------
|    &     |    Bitwise AND     |
 --------------------------------
|    |     |    Bitwise OR      |
 --------------------------------
|    ^     |    Bitwise XOR     |
 --------------------------------
|    ~     | Bitwise COMPLEMENT |
 --------------------------------
|    <<    |    SHIFT LEFT      |
 --------------------------------
|    >>    |    SHIFT RIGHT     |
 --------------------------------
*/

/*
  if a = 12 => 00001100 (in binary)
     b = 25 => 00011001 (in binary)

              00001100
            & 00011001
--------------------------------            
            = 00001000 only 1&1=1
            = 8 (in decimal)
*/
int AND(int a, int b) {return a&b;}

/*
  if a = 12 => 00001100 (in binary)
     b = 25 => 00011001 (in binary)

              00001100
            | 00011001
--------------------------------            
            = 00011101 operand運算元 |(or) 1 = 1
            = 29 (in decimal)
*/
int OR(int a, int b) {return a|b;}

/*
  if a = 12 => 00001100 (in binary)
     b = 25 => 00011001 (in binary)

              00001100
            ^ 00011001
--------------------------------            
            = 00010101 a number two operands are oppsite = 1
            = 21 (in decimal)
*/
int XOR(int a, int b) {return a^b;}

/*
  if a = 12 => 00001100 (in binary)
       
    (1st XOR)      00001100 = 11110011 (change 0 to 1, and 1 to 0)
    (2st XOR)      11110011 = 00001101 (change 0 to 1, and 1 to 0, keep first bit = 1)
    the last bit of 1st XOR result = 1 means negative, 0 means postive
    so ~a = -(00001101) = -13 (-a(+1))
*/
int Complement(int a) {return ~a;}

/*
  if a = 12 => 00001100 (in binary)
     a>>2   => 00000011 = 3 (in decimal)
     a>>1   => 00000110 = 6 (in decimal)
     a>>0   => 00001100 = 12 (in decimal)
*/
int RightShift(int a,int shiftbit) {return a<<shiftbit;}

/*
  if a = 12 => 00001100 (in binary)
     a>>2   => 00110000 = 48 (in decimal)
     a>>1   => 00011000 = 24 (in decimal)
     a>>0   => 00001100 = 12 (in decimal)
*/
int LeftShift(int a,int shiftbit) {return a>>shiftbit;}



int main()
{   
    printf("%d",LeftShift(12,2));
    return 0;
}