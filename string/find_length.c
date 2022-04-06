#include<stdio.h>
#include<string.h>

int main(){
    //find string length without strlen()
    char str[100];
    int count = 0;
    printf("please enter the sentance :");
    fgets(str,sizeof(str),stdin);
    int i;
    //when fgets detect the user press enter 
    //the '\n'will be added to the string before '\0'
    for ( i = 0; str[i] != '\n'; ++i);
    printf("(fgets)There are %d characters in string\n",i);
    
    //using scanf
    int j;
    for ( j = 0; str[j] != '\n'; ++j);
    printf("(scanf)There are %d characters in string\n",j);

    return 0;
}
