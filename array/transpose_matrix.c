#include<stdio.h>

int main(){
    int col,row;
    printf("please enter number of row : ");
    scanf("%d",&row);
    printf("please enter number of col : ");
    scanf("%d",&col);

    int matrix[row][col];
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("Element a%d%d : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
        
    }
    //display input matrix
    printf("Input matrix : \n");
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    //transpose matrix
    int matrix_tr[col][row];
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            matrix_tr[i][j]=matrix[j][i];
        }
    }
    //display transpose matrix
    printf("transpose matrix : \n");
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            printf("%d ",matrix_tr[i][j]);
        }
        printf("\n");
    }

    return 0;
}