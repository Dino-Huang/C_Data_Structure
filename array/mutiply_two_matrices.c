#include<stdio.h>

//when muti dimensions array are arugments, u can ignore to declare row,but col must be specified
void mutiply_two_matrices(int M1[][10],int M2[][10],int r1,int c1,int r2,int c2){
    int result[r1][c2];
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            result[i][j]=0;
        }
        
    }

    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            for (size_t k = 0; k < c1; k++)
            {
                result[i][j]+=(M1[i][k]*M2[k][j]);
            }
            
        }
        
    }

    printf("M1 * M2 = \n");
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }    
}

int main(){
    int r1,c1,r2,c2;

    printf("please enter number of rows and cols of first matrix:\n");
    printf("rows of M1 :");
    scanf("%d",&r1);
    printf("cols of M1 :");
    scanf("%d",&c1);
    printf("please enter number of rows and cols of second matrix:\n");
    printf("rows of M2 :");
    scanf("%d",&r2);
    printf("cols of M2 :");
    scanf("%d",&c2);

    while(c1 != r2){
        printf("column of M1 is not equal to row of M2\n");
        printf("rows of M1 :");
        scanf("%d",&r1);
        printf("cols of M1 :");
        scanf("%d",&c1);
        printf("rows of M2 :");
        scanf("%d",&r2);
        printf("cols of M2 :");
        scanf("%d",&c2);
    }
    //the size of row must equal to the size of argument that send into the function
    //if here use c1,c2 its not work
    int M1[10][10],M2[10][10];
    printf("please enter the element of M1 : \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Element %d : ",i*c1+j+1);
            scanf("%d",&M1[i][j]);        
        }
    }
    printf("please enter the element of M2 : \n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Element %d : ",i*c2+j+1);
            scanf("%d",&M2[i][j]);
        }
    }

    mutiply_two_matrices(M1,M2,r1,c1,r2,c2);
    
    return 0;
}