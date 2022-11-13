#include<iostream>
using namespace std;
/*
Given an unsorted array A of size N of non-negative integers, find a continuous
subarray which adds to a given number S.
*/
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    
    int start, end;
    for(int i=0;i<n;i++){
        int finalSum = 0;
        for(int j=i;j<n;j++){
            finalSum += arr[j];
            if(finalSum == sum){
                cout<<i+1<<" to "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}