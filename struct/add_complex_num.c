#include<stdio.h>

struct complex{
    float Re;
    float Im;
};

int main(){
    struct complex complex1,complex2,result;
    printf(" please enter real part of complex1:\n");
    scanf("%f",&complex1.Re);
    printf(" please enter imaginary part of complex1:\n");
    scanf("%f",&complex1.Im);
     printf(" please enter real part of complex2:\n");
    scanf("%f",&complex2.Re);
    printf(" please enter imaginary part of complex2:\n");
    scanf("%f",&complex2.Im);
    printf(" Result of complex1 + complex2:\n");
    result.Re = complex1.Re + complex2.Re;
    result.Im = complex1.Im + complex2.Im;
    if(result.Im<0)
    {
        printf("Result : %.1f - %.1fi\n",result.Re,-(result.Im));    
    }else{
        printf("Result : %.1f + %.1fi\n",result.Re,(result.Im));
    }
    return 0;
}