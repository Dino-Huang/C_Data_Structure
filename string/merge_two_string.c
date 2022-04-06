#include<stdio.h>

int main(){
    char str1[20]="Hello ";
    char str2[]="world";
    int len1=0;
    for (size_t i = 0; str1[i] !='\0'; i++)
    {
        ++len1;
    }
    for (size_t i = 0; str2[i]!='\0'; ++i,++len1)
    {
        str1[len1]=str2[i];
    }
    printf("merge result : %s\n",str1);

    return 0;
}