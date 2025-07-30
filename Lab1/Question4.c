#include <stdio.h>

void selection_sort(int* arr, int n);

int main(){
    int n; //Number of elements in array
    int* arr;//array
    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter number in %d index: ",i);
        scanf("%d",&arr[i]);
    }
    selection_sort(arr, n);
    printf("sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void selection_sort(int* arr, int n){
    for (int i = 0; i < n; i ++){
        int min_index = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int swap = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = swap;
    }
}
