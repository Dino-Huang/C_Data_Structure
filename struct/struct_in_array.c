#include<stdio.h>

struct student{
    char name[100];
    int marks;
};

int main(){
    struct student s[5];
    for (size_t i = 0; i < 5; i++)
    {
        printf("please enter student %d's info:\n",i+1);
        printf("Name : ");
        scanf("%s",&s[i].name);
        printf("Marks : ");
        scanf("%d",&s[i].marks);
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("student %d's info:\n",i+1);
        printf("Name : %s\n",s[i].name);
        printf("Name : %d\n",s[i].marks);
    }
    
    
    return 0;
}