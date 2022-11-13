#include<iostream>
using namespace std;

/*
Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2
*/
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int counter = 0;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            continue;
        }
        else{
            bool flag = false;
            int j = 0;
            while(flag == false and j < n){
                if(counter == arr[j]){
                    flag = true;
                }
                j++;
            }
            if(flag==false){
                cout<<counter<<endl;
                return 0;
            }
        }
        counter++;
    }
    cout<<"No"<<endl;
    return 0;
}