#include<iostream>
#include<climits>
using namespace std;

void sort(int arr[], int n);
bool pairSum(int arr[], int n, int k);

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin >> k;

    sort(arr, n);
    cout<<pairSum(arr, n, k)<<endl;
    return 0;
}

void sort(int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j <n; j++){
            if(arr[j]<arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

bool pairSum(int arr[], int n, int k){
    int low = 0;
    int high = n - 1;
    while(low < high){
        int currentSum = arr[low] + arr[high];
        if(currentSum == k){
            return true;
        }
        else if(currentSum < k){
            low = low + 1;
            currentSum = 0;
        }
        else{
            high = high - 1;
            currentSum = 0;
        }
    }
    return false;
}