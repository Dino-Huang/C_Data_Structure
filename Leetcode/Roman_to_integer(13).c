#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

* I can be placed before V (5) and X (10) to make 4 and 9.  IV = 4 IX = 9
* X can be placed before L (50) and C (100) to make 40 and 90. 
* C can be placed before D (500) and M (1000) to make 400 and 900.

*/
int value(char s){
    switch(s){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

int BestMethod(char* s)
{
    int sum = 0;
    for (int i = 0; s[i] != '\0' ; i++)//the end of s is '\0'
    {
        if(value(s[i])<value(s[i+1]))//like IV is a combination 
        {
            sum = sum - value(s[i]);// minus front part and then add next part
        }else{
            sum += value(s[i]);
        }
    }
    return sum;
}

int romanToInt(char* s){

    int temp = 0;
    
    for (int i = 0; i < strlen(s); i++)// or sizeof(s)-1
    {
        
        if (s[i] == 'I')
        {
            if(s[i+1] =='V')
            {
                temp+=4;
                i++;
            }
            else if(s[i+1] =='X')
            {
                temp+=9;
                i++;
            }
            else
            {
                temp++;
            }
        }
        else if(s[i] == 'V'){
            temp+=5;
        }
        else if(s[i] == 'X')
        {
            if(s[i+1] =='L')
            {
                temp+=40;
                i++;
            }
            else if(s[i+1] =='C')
            {
                temp+=90;
                i++;
            }
            else
            {
                temp+=10;
            }
        }
        else if(s[i] == 'L'){
            temp+=50;
        }
        else if(s[i] == 'C')
        {
             if(s[i+1] =='D')
            {
                temp+=400;
                i++;
            }
            else if(s[i+1] =='M')
            {
                temp+=900;
                i++;
            }
            else
            {
                temp+=100;
            }
        }
        else if(s[i] == 'D'){
            temp+=500;
        }
        else if(s[i] == 'M'){
            temp+=1000;
        }
    }
    
    return temp;
}

int main(){
    //s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    char s[]="MCMXCIV";
    printf("Input : %s\n",s);
    //int value = romanToInt(s);
    int value = BestMethod(s);
    printf("Output : %d\n",value);
    return 0;
}