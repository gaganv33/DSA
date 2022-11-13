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
    int number;
    int maxIndex = -1;
    int maxCount = INT_MIN;
    for(int i=0;i<n;i++){
        if(number == arr[i]){
            break;
        }
        else{
            int count = 0;
            number = arr[i];
            for(int j=0; j<n;j++){
                if(number == arr[j]){
                    count ++;
                }
            }
            // Updating the value of the maximum count
            if(count > maxCount){
                maxCount = count;
                maxIndex = i;
            }
        }
    }
    cout<<"The maximum reapeating number is occuring at position: "<<maxIndex+1<<endl;
}