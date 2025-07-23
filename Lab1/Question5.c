#include <stdio.h>

void insertion_sort(int* arr, int n);

int main(){
    int n; //Number of elements in array
    int* arr;//array
    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter number in %d index: ",i);
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d: %d\n",i,arr[i]);
    }
}

void insertion_sort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; // Here, We do not use j++ or j-- as the precedence of ++ affects the algorithim
            j=j-1;
        }
        arr[j+1] = key;
    }
}
