#include<iostream>
#include<climits>
using namespace std;
int maximumNumber(int array[], int n);
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i ++){
        cin>>array[i];
    }
    int maxNum = maximumNumber(array, n);
    cout<<"Maximu number: "<<maxNum<<endl;
    return 0;
}
int maximumNumber(int array[], int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}