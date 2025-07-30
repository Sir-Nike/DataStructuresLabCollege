#include <stdio.h>

int binary_search(int* arr, int n, int target);

int main(){
    int n; //Number of elements in array
    int* arr;//array
    int target;//value to be found

    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter number in %d index: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d",&target);

    int target_index = binary_search(arr, n, target);

    if (target_index != -1){
        printf("Target index is: %d\n",target_index);
    }
    else printf("Target is not in array\n");
}
int binary_search(int* arr, int n, int target){

    int low = 0;
    int high = n-1;
    int mid = 0;

    while (low <= high){
        mid = (low + high)/2;
        if (target == arr[mid]){
            return mid;
        }
        if (target < arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
