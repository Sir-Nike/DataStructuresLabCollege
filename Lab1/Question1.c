#include <stdio.h>

int LinearSearch(int* arr, int n, int target);

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

    int target_index = LinearSearch(arr,n,target);

    if (target_index != -1){
        printf("Target index is: %d\n",target_index);
    }
    else printf("Target is not in array\n");
}


int LinearSearch(int* arr, int n, int target){
    for (int i = 0; i < n; i ++){
        if(*(arr + i) == target){
            return i;
        }
    }
    return -1;
}
