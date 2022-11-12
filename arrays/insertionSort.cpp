#include<iostream>
using namespace std;
int insertionSort(int array[], int n);
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i < n; i++){
        cin>>array[i];
    }
    insertionSort(array, n);
}
int insertionSort(int array[], int n){
    for(int i=1; i<n; i++){
        int current = array[i];
        int j=i-1;
        while(array[j] > current and j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = current;
    }
    for(int i= 0;i<n;i++){
        cout<<array[i]<<" ";
    }
}