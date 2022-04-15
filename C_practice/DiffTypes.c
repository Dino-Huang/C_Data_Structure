#include<stdio.h>
#include<stdlib.h>

int main(){
    
    char a[]="john";
    printf("a : %s\n",a);
    printf("addr of a : %p\n",a);
    printf("addr of a[0] : %p\n",&a[0]);
    printf("char of *a : %c\n",*a);
    printf("char of a[0] : %c\n",a[0]);
    printf("addr & of a : %p\n",&a);
    printf("addr of a+1 : %p\n",a+1);
    printf("char of a+1 : %c\n",*(a+1));
    printf("addr & of a+1 : %p\n",&(a[1]));
    printf("*a : %c\n",*a);
    printf("*(a+1) : %c\n",*(a+1));
    
    char* b = a;//ptr to char array
    printf("b : %c\n",*b);
    printf("size of char ptr : %zu\n",sizeof(char*));
    printf("b : %s\n",b);
    printf("addr of b : %p\n",b);
    printf("addr of b[0] : %p\n",&b[0]);
    printf("char of *b : %c\n",*b);
    printf("char of b[0] : %c\n",b[0]);
    printf("char of b[1] : %c\n",b[1]);
    printf("addr & of b : %p\n",&b);
    printf("addr of b+1 : %p\n",b+1);
    printf("char of b+1 : %c\n",*(b+1));
    printf("addr & of b+1 : %p\n",&(b[1]));
    printf("*b : %c\n",*b);
    printf("*(b+1) : %c\n",*(b+1));
    

    char* c = "def";
    const char* d = c;//add const to let compiler know its read only
    //*d = 'f';//string lteral is read only, u cant wirte it
    printf("addr of d[0] : %p\n",d);
    printf("addr of d[1] : %p\n",d+1);
    printf("d[0] : %c\n",d[0]);
    printf("d : %s\n",d);//%s assume user input a ptr to char
    printf("*d : %c\n",*d);
    printf("*(d+1) : %c\n",*(d+1));


    return 0;
}