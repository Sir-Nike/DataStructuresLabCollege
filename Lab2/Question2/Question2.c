#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int n, int idx) {
    if (idx >= n) return;
    int *min = arr + idx;
    for (int *p = arr + idx + 1; p < arr + n; p++)
    if (*p < *min) min = p;
    if (min != arr + idx) {
        int tmp = *min;
        *min = *(arr + idx);
        *(arr + idx) = tmp;
    }
    selection_sort(arr, n, idx + 1);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", arr + i);
    }

    selection_sort(arr, n, 0);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");

    free(arr);
    return 0;
}
