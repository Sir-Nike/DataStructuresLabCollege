#include <stdio.h>
#include <stdlib.h>

void create_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) {
            printf("Enter matrix[%d][%d]: ", i, j);
            scanf("%d", (matrix + i * cols + j));
        }
}

void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++, printf("\n")) for (int j = 0; j < cols; j++)printf("%d\t", *(matrix + i * cols + j));
}

int *product_matrix(int *a, int r1, int c1, int *b, int r2, int c2) {
    if (c1 != r2) return NULL;
    int *result = malloc(r1 * c2 * sizeof(int));
    if (!result) return NULL;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            int *c = result + i * c2 + j;
            *c = 0;
            for (int k = 0; k < c1; k++) *c += *(a + i * c1 + k) * *(b + k * c2 + j);
        }

    return result;
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter size of First Matrix (rows cols): ");
    scanf("%d %d", &r1, &c1);
    int *m1 = malloc(r1 * c1 * sizeof(int));
    if (!m1) return printf("Memory allocation failed.\n"), 1;
    create_matrix(m1, r1, c1);

    printf("Enter size of Second Matrix (rows cols): ");
    scanf("%d %d", &r2, &c2);
    int *m2 = malloc(r2 * c2 * sizeof(int));
    if (!m2) return printf("Memory allocation failed.\n"), free(m1), 1;
    create_matrix(m2, r2, c2);

    int *m3 = product_matrix(m1, r1, c1, m2, r2, c2);
    if (!m3) return printf("Matrix multiplication not possible.\n"), free(m1), free(m2), 1;

    printf("Product Matrix:\n");
    print_matrix(m3, r1, c2);

    free(m1); free(m2); free(m3);
    return 0;
}
