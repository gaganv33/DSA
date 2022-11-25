#include<iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int row = 0;
    int column = m - 1;
    while(row < n && column >= 0){
        if(arr[row][column] == k){
            cout<<"Element found at: "<<row<<" "<<column<<endl;
            return 0;
        }
        if(arr[row][column] > k){
            column = column - 1;
        }
        else{
            row = row + 1;
        }
    }
    cout<<"Element not found in the 2-D array."<<endl;
    return 0;
}