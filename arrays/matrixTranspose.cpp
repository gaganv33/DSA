#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    int new_arr[N][N];

    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            new_arr[i][j] = arr[j][i];
        }
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<new_arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}