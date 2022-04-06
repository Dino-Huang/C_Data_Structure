#include<stdio.h>

//a,b,c=>c,a,b
void cyclicSwap(int* a, int* b ,int* c){
    int temp;
    temp = *b;// a=a b=b c=c temp=b
    *b = *a;// a=a b=a c=c temp=b
    *a = *c;// a=c b=a c=c temp=b
    *c = temp;
}

int main(){
    int *a,*b,*c;
    printf("please enter three numbers resepectivly : \n");
    printf("a : ");
    scanf("%d",&a);
    printf("b : ");
    scanf("%d",&b);
    printf("c : ");
    scanf("%d",&c);

    cyclicSwap(&a,&b,&c);

    printf("after swaping : \n");
    printf("a : %d\n",a);
    printf("b : %d\n",b);
    printf("c : %d\n",c);
    return 0;
}