#include<stdio.h>

struct info{
    int feet;
    float inch;
};

int main(){
    struct info p1,p2,sum;
    printf("please enter p1's info:\n");
    printf("feet : ");
    scanf("%d",&p1.feet);
    printf("inch : ");
    scanf("%f",&p1.inch);
    printf("please enter p2's info:\n");
    printf("feet : ");
    scanf("%d",&p2.feet);
    printf("inch : ");
    scanf("%f",&p2.inch);

    //p1+p2
    sum.feet=p1.feet+p2.feet;
    sum.inch=p1.inch+p2.inch;
    printf("sum of p1 and p2:\n");
    printf("feet : %d",sum.feet);
    printf("inch : %f",sum.inch);
    return 0;
}