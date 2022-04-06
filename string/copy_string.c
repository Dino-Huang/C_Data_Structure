#include<stdio.h>

int main(){
    char str1[100];
    char str2[100];
    printf("Please enter a sentance :\n");
    fgets(str1,sizeof(str1),stdin);
    //copy str1 to s2
    int i;
    for ( i =0; str1[i] !='\0'; i++)
    {
        str2[i]=str1[i];
    }
    str2[i]='\0';
    printf("str1 : %s",str1);
    printf("str2 : %s",str2);
    
    return 0;
}