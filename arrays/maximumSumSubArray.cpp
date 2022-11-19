#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum = INT_MIN;
    int start = -1;
    int ending = -1;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i; j<n;j++){
            sum += arr[j];
            if(sum > maxSum){
                maxSum = sum;
                start = i;
                ending = j;
            }
        }
    }
    cout<<"Starting value is: "<<start<<endl;
    cout<<"Ending value is: "<<ending<<endl;
    cout<<"Maximum sum: "<<maxSum<<endl;
    return 0;
}