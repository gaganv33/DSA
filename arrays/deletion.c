#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[100];
    if(n > 100){
        printf("Reached the maximum limit.");
        return 0;
    }
    printf("Enter the numbers seperated by a space:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int index;
    printf("Enter the index for deletion:\n");
    scanf("%d", &index);
    if(index >= n){
        printf("Cannot delete the number.");
        return 0;
    }
    
    for(int i=index+1;i<n;i++){
        arr[i-1] = arr[i];
    }
    n -=1;
    printf("The array after delete operation:\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}