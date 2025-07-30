#include <stdio.h>
#include <stdlib.h>

void create_matrix(int *matrix, int row, int col);
void print_matrix(int *matrix, int row, int col);
int *product_matrix(int *matrix1, int row1, int col1, int *matrix2, int row2, int col2);

void clear_input_buffer()
{
    while (getchar() != '\n' && getchar() != EOF);
}

int main(){
    printf("First Matrix\n");

    int row1;
    int col1;

    printf("Enter number of Rows, Columns: ");
    scanf("%d, %d",&row1, &col1);
    int *matrix1 = (int *)malloc(row1*col1*sizeof(int));
    if (!matrix1)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    create_matrix( matrix1, row1, col1);
    print_matrix(matrix1, row1, col1);

    printf("Second Matrix\n");

    int row2;
    int col2;

    printf("Enter number of Rows, Columns: ");
    clear_input_buffer();
    scanf("%d, %d",&row2, &col2);
    int *matrix2 = (int *)malloc(row2 * col2 *sizeof(int));
    if (!matrix2)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    create_matrix(matrix2, row2, col2);
    print_matrix(matrix2, row2, col2);

    int *matrix3 = product_matrix(matrix1, row1, col1,matrix2, row2, col2);
    if (!matrix3)
    {
        if (row1 != col2) printf("Error in assigning values: Row of fist array not equal to column of second\n");
        else printf("Error in memory allocation.\n");
        return 1;
    }
    printf("Product of First and Second Matrix: \n");
    print_matrix(matrix3, row1, col2);

    free(matrix1);
    free(matrix2);
    free(matrix3);
    return 0;
}

void create_matrix(int *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter the element in matrix[%d][%d] ", i, j);
            clear_input_buffer();
            scanf("%d", matrix + (i*col) + j);
        }
    }
}

void print_matrix(int *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("matrix[%d][%d]: ",i ,j ,*(matrix + (i*col) + j));
            printf("\t");
        }
        printf("\n");
    }
}

int *product_matrix(int *matrix1, int row1, int col1, int *matrix2, int row2, int col2)
{
    if (col1 != row2)
    {
        return NULL;
    }

    int *matrix3 = (int *)malloc(row1 * col2* sizeof(int));

    if (!matrix3)
    {
        return NULL;
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
                *(matrix3 + (i*col2) + j) = 0;
            for (int k = 0; k < col1; k++)
            {
                *(matrix3 + (i*col2) + j) += *(matrix1 + (i*col1) + k) * *(matrix2 + (k*col2) + j);
            }
        }
    }

    return matrix3;
}
