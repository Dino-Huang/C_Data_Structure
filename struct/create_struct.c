#include <stdio.h>
struct student {
    char name[50];
    int roll;
    float marks;
    //%f for float %lf for double
};

int main(){
    struct student s;
    printf("student name:");
    scanf("%s",&s.name);
    printf("student roll:");
    scanf("%d",&s.roll);
    printf("student marks:");
    scanf("%f",&s.marks);

    printf("display info:\n");
    printf("student name : %s\n",s.name);
    printf("student roll numbers : %d\n",s.roll);
    printf("student marks : %.1f\n",s.marks);

    return 0;
}