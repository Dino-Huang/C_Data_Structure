#include<stdio.h>
#include<stdlib.h>

int main(){
    char a[]="abc";
    a[0]='q';
    char *b = a;
    char *c = "def";
    b[0]='r';

    printf("a : %s\n",a);

    printf("b : %s\n",b);
    //printf("b : %s\n",*b);
    
    printf("c : %s\n",c);
    printf("c : %s\n",*c);

    char x[] = {"abc"};
    char *y = x;
    printf("x : %c\n",x[0]);
    printf("y : %c\n",*y);
    return 0;
}