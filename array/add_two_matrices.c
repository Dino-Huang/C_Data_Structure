#include<stdio.h>


int main(){
    int row,col;
    printf("please enter the number of row(0~5) : ");
    scanf("%d",&row);
    printf("please enter the number of col(0~5) : ");
    scanf("%d",&col);

    
    int Matrix1[row][col],Matrix2[row][col];

    printf("please enter the first matrix :\n");
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("Element %d : ",i*row+j+1);
            scanf("%d",&Matrix1[i][j]);
        }
    }

    printf("please enter the second matrix :\n");
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < col; ++j)
        {
            printf("Element %d : ",i*row+j+1);
            scanf("%d",&Matrix2[i][j]);
        }
    }

    //sum of matrices
    printf("Sum of two matrices : \n");
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < col; ++j)
        {
            Matrix1[i][j]+=Matrix2[i][j];
            printf("%d ",Matrix1[i][j]);
        }
        printf("\n");
        
    }
    
    
    return 0;
}