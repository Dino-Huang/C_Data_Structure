#include <stdio.h>
#include <stdlib.h>

void HalfPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}

void FullPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j <= height; j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
}

void NumberPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j <= height; j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    
}

void InverseNumberPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j <= height; j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            printf("%d ",height-i+1);
        }
        printf("\n");
    }
    
}

void SortNumberPyramid(int height)
{
    int total = (1+(2*height-1))*height/2-1;
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j <= height; j++)
        {
            if(total < 10){
                printf("  ");
            }else
                printf("   ");
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            if(total < 10){
                printf(" %d ",total);
            }
            else
            {
                printf("%d ",total);
            }
            total--;
        }
        printf("\n");
    }
    
}

int main(){

    int height;
    printf("please enter the height of pyramid : ");
    scanf("%d",&height);

    //HalfPyramid(height);
    //FullPyramid(height);
    //NumberPyramid(height);
    //InverseNumberPyramid(height);
    SortNumberPyramid(height);
   
    return 0;
}