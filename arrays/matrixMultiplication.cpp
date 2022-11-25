#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of rows and columns for the matrix-1"<<endl;
    int n1, m1;
    cin>>n1>>m1;

    cout<<"Enter the number of rows and columns for the matrix-2"<<endl;
    int n2, m2;
    cin>>n2>>m2;

    if(m1 != n2){
        cout<<"Cannot multiply the two matrices."<<endl;
    }
    else{
        int arr1[n1][m1];
        int arr2[n2][m2];
        cout<<"Enter the numbers for matrix-1"<<endl;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                cin>>arr1[i][j];
            }
        }
        cout<<"Enter the numbers for matrix-2"<<endl;
        for(int i=0;i<n2;i++){
            for(int j=0; j<m2;j++){
                cin>>arr2[i][j];
            }
        }

        int new_arr[n1][m2];
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                int sum = 0;
                for(int k=0; k<n2;k++){
                    int answer = int(arr1[i][k]) * int(arr2[k][j]);
                    sum = sum + answer;
                }
                new_arr[i][j] = sum;
            }
        }
        cout<<"After mutlplication of the two matrices"<<endl;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                cout<<new_arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

