#include <stdio.h>
#include <stdlib.h>

int smallest_element(int* arr, int n);

int main(){
    int n;
    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    if(n == 0){
        printf("Do not enter array size 0\n");
        return 1;
    }

    int* arr = malloc(n*sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d",arr+i);

    int smallest = smallest_element(arr, n);
    printf("Smallest element of array is: %d\n",smallest);
    free(arr);
    return 0;
}

int smallest_element(int* arr, int n){
    int smallest = *arr;
    for (int i = 0; i < n; i++){
        if (*(arr+i) < smallest){
            smallest = *(arr+i);
        }
    }
    return smallest;
}
