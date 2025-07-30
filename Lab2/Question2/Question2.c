#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* arr, int n, int index);

int main(){
    int n; //Number of elements in array
    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    int* arr = malloc(n*sizeof(int));//array
    for(int i = 0; i < n; i++){
        printf("Enter number in %d index: ",i);
        scanf("%d",arr + i);
    }
    selection_sort(arr, n, 0);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) printf("%d \t",*(arr + i));
    printf("\n");
    free(arr);
    return 0;
}

void selection_sort(int* arr, int n, int index){

    if (index >= n) return;

    int min = index;
    for (int i = index + 1; i < n; i++){
        if (*(arr + i) < *(arr + min)){
                min = i;
        }
    }

    if (*(arr + min) != *(arr + index)){
        int temp = *(arr + min);
        *(arr + min) = *(arr + index);
        *(arr + index) = temp;
    }

    selection_sort(arr, n, index + 1);
}
