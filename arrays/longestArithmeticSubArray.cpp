#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int counterArray[n-1];
    for(int i=0;i<n-1;i++){
        int counter = 0;
        int difference = array[i] - array[i + 1];
        for(int j =i; j<n-1;j++){
            if((array[j] - array[j + 1]) == difference){
                counter += 1;
            }
            else{
                break;
            }
        }
        counterArray[i] = counter + 1;
    }
    int ans = INT_MIN;
    for(int i=0; i<n - 1; i++){
        if(counterArray[i] > ans){
            ans = counterArray[i];
        }
    }
    cout<<"The longest arithmetic subarray is: "<<ans<<endl;
    return 0;
}