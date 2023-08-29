#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int r;
    printf("Enter the maximum range of the disk ");
    scanf("%d", &r);
    int n;
    printf("Enter the size of the request queue ");
    scanf("%d", &n);

    int head;
    printf("Enter the head position ");
    scanf("%d", &head);


    // the head always moves to the right
    int right[n];
    int left[n];
    int j = 0; // left
    int k = 0; // right
    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        if(val < head){
            left[j] = val;
            j++;
        }
        else{
            right[k] = val;
            k++;
        }
    }
    int rightSize = k;
    int leftSize = j;
    sort(right, rightSize);
    sort(left, leftSize);
    int seekTime = (r - 1) - head + (r - 1) + left[0];
    for(int i = 0; i < rightSize; i++){
        printf("Head moves from %d to %d\n", head, right[i]);
        head = right[i];
    }
    printf("Head moves from %d to %d\n", head, (r - 1));
    head = r - 1;
    for(int i = leftSize - 1; i >= 0; i--){
        printf("Head moves from %d to %d\n", head, left[i]);
        head = left[i];
    }
    printf("Total seek time: %d", seekTime);
    return 0;
}