#include<iostream>
#include<numeric>
using namespace std;
int average(int arr[], int n)throw(string){
    if(n==0){
        throw string("Length of the array is zero");
    }
    else{
        int sum = 0;
        sum = accumulate(arr, arr+n, sum);
        return sum;
    }
}
int main(){
    cout<<"Number of elements"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements seperared by a space"<<endl;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    try{
        int res = average(arr, n);
        cout<<res;
    }
    catch(string &e){
        cout<<e<<endl;
    }
}