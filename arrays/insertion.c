#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter the numbers:\n");

    if(n >100){
        printf("Reached maximum limit.");
        return 0;
    }

    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int element, index;
    printf("Enter the number for inserting:\n");
    scanf("%d", &element);
    printf("Position for inserting in the array:\n");
    scanf("%d", &index);
    
    for(int i=n-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    n += 1;
    for(int i=0;i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}