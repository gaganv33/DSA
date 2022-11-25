#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin >> m >> n;
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int row_start = 0;
    int row_end = m - 1;
    int column_start = 0;
    int column_end = n  - 1;

    while(row_start <= row_end && column_start <= column_end){
        for(int col = column_start; col <= column_end; col++){
            cout<<arr[row_start][col]<<" ";
        }
        row_start++;
        for(int row=row_start; row <= row_end; row++){
            cout<<arr[column_end][row]<<" ";
        }
        column_end--;
        for(int col=column_end; col>=column_start;col--){
            cout<<arr[row_end][col]<<" ";
        }
        row_end--;
        for(int row=row_end; row>=row_start;row--){
            cout<<arr[row][column_start]<<" ";
        }
        column_start++;
    }
    cout<<endl;
    return 0;
}