#include <stdio.h>

void bubble_sort(int* arr, int n);

int main(){
    int n; //Number of elements in array
    int* arr;//array

    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter number in %d index: ",i);
        scanf("%d",&arr[i]);
    }

    bubble_sort(arr, n);
    printf("sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int* arr, int n){

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
}
