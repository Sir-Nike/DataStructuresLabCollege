#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("First Matrix\n");
    int row1;
    int col1;

    printf("Enter number of Rows, Columns: ");
    scanf("%d, %d",&row, &col);
    int *matrix1 = (int *)malloc(row*col*sizeof(int));

    for (int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            printf("Enter the %d row, %d column element: ", i, j);
            scanf("%d", matrix1 + (i*col1) + j);
        }
    }

    for (int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            printf("%d row, %d column: %d",i ,j ,*(matrix1 + (i*col1) + j));
            printf("\t");
        }
        printf("\n");
    }

    printf("Second Matrix\n");

    int row2;
    int col2;

    printf("Enter number of Rows, Columns: ");
    scanf("%d, %d",&row, &col);
    int *matrix2 = (int *)malloc(row2 * col2 *sizeof(int));

    for (int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            printf("Enter the %d row, %d column element: ", i, j);
            scanf("%d", matrix2 + (i*col2) + j);
        }
    }

    for (int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            printf("%d row, %d column: %d",i ,j ,*(matrix2 + (i*col2) + j));
            printf("\t");
        }
        printf("\n");
    }
}
