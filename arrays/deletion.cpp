#include<iostream>
using namespace std;
int delete_operation(int arr[], int cur_size, int pos);

int main(){
    int n, pos, arr[1000];
    cin>>n;
    int cur_size = 0;
    for(int i = 0; i < n; i++){
        cur_size = cur_size + 1;
        cin>>arr[i];
    }
    cin>>pos;
    cur_size = delete_operation(arr, cur_size, pos);
    for(int i = 0; i < cur_size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
int delete_operation(int arr[], int cur_size, int pos){
    for(int i = pos - 1; i < cur_size; i++){
        arr[i] = arr[i+1];
    }
    return cur_size - 1;
}