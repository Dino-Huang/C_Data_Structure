#include<stdio.h>
#include<stdlib.h>

//compare two string ,return 1 if they are the same, otherwise return 0
int self_strcmp(char *a, char *b){
    while(*a!='\0')
    {
        //camper a and b
        if(*a != *b)
        {
            return 0;
        }
        //move a and b 
        ++a;
        ++b;
    }
    if (*a == *b)
    {
        return 1;// a and b are the same
    }
    return 0;
}

int main()
{

    char str_a[]="abc";
    char str_b[]="abc";

    if (self_strcmp(str_a,str_b))
    {
        printf("two strings are the same !\n");
    }else{
        printf("two strings are the different !\n");
    }
    
    

    return 0;
}