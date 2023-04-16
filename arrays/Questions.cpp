#include<iostream>
using namespace std;

int largestElement(int arr[], int n);
void checkIfSorted(int arr[], int n);
void secondLargestElement(int arr[], int n);
void secondMax(int arr[], int n);
void reverseArray(int arr[], int n);
int removeDuplicates(int arr[], int n);
void leftRotate(int arr[], int n);
void leftRotateByD(int arr[], int n, int d);
void moveZerosEnd(int arr[], int n);

int main(){
    int n, arr[1000];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int index = largestElement(arr, n);
    printf("Index: %d\n", index);
    checkIfSorted(arr, n);
    secondLargestElement(arr, n);
    secondMax(arr, n);
    reverseArray(arr, n);
    cout<<"Reversing an array"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    n = removeDuplicates(arr, n);
    cout<<"Remove duplicates"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    leftRotate(arr, n);
    int d;
    cin>>d;
    leftRotateByD(arr, n, d);
    moveZerosEnd(arr, n);
    return 0;
}
int largestElement(int arr[], int n){
    int max = arr[0];
    int index = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    printf("Max: %d\n", max);
    return index;
}
void checkIfSorted(int arr[], int n){
    bool sorted = true;
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]){
            sorted = false;
            break;
        }
    }
    printf("Sorted: %d\n", sorted);
}

void secondLargestElement(int arr[], int n){
    int max, maxIndex, secondMax, secondMaxIndex;
    max = arr[0];
    maxIndex = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    secondMaxIndex = -1;
    secondMax = -2147483648;
    for(int j = 0; j < n; j++){
        if(arr[j] > secondMax && arr[j] < max){
            secondMax = arr[j];
            secondMaxIndex = j;
        }
    }
    if(secondMaxIndex != -1){
        printf("Second largest element: %d\n", secondMax);
        printf("Second largest element index: %d\n", secondMaxIndex);
    }
}
void secondMax(int arr[], int n){
    int second = -1, largest = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[largest]){
            if(arr[i] != arr[largest]){
                second = largest;
                largest = i;
            }
        }
        else{
            if(second == -1 || arr[i] > arr[second]){
                second = i;
            }
        }
    }
    if(second == -1){
        cout<<"No second largest element\n"<<endl;
    }
    else{
        cout<<"Second largest element is: "<<arr[second]<<" index: "<<second<<endl;
    }
}
void reverseArray(int arr[], int n){
    int low = 0, high = n - 1;
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    return;
}
int removeDuplicates(int arr[], int n){
    // Removing duplicated from sorted array
    int temp = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[temp - 1]){
            arr[temp] = arr[i];
            temp++;
        }
    }
    return temp;
}
void leftRotate(int arr[], int n){
    cout<<"Left rotate by one"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int first = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n - 1] = first;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void leftRotateByD(int arr[], int n, int d){
    int temp[n];
    for(int i = 0; i < d; i++){
        temp[n - d + i] = arr[i];
    }
    for(int i = d; i < n; i++){
        temp[i - d] = arr[i];
    }
    for(int i =0 ; i < n; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void moveZerosEnd(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            int temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}