#include<iostream>
using namespace std;
int insert(int arr[], int cur_size, int x, int pos);
int main(){
    int n;
    cin>>n;
    int arr[1000];
    int cur_size = 0;
    for(int i = 0; i < n; i++){
        cur_size = cur_size + 1;
        cin>>arr[i];
    }
    int x, pos;
    cin>>x>>pos;
    cur_size = insert(arr, cur_size, x, pos);
    for(int i = 0; i < cur_size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

int insert(int arr[], int cur_size, int x, int pos){
    if (cur_size == 1000){
        return 1000;
    }
    int idx = pos - 1;
    int temp = cur_size - 1;
    for(int i = temp; i >= idx; i--){
        arr[i+1] = arr[i];
    }
    arr[idx] = x;
    return cur_size + 1;
}