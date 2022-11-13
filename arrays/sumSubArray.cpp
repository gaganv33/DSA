#include<iostream>
using namespace std;
void sumSubArray(int array[], int n);
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    sumSubArray(array, n);
}
void sumSubArray(int array[], int n){
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += array[j];
            cout<<sum<<endl;
        }
    }
}