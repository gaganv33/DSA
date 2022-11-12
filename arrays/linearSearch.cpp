#include<iostream>
using namespace std;
int linearSearch(int array[], int n, int key);
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int key;
    cin>>key;

    int index = linearSearch(array, n, key);
    if(index==-1){
        cout<<"The number "<<key<<" not in the array of integers"<<endl;
    }
    else{
        cout<<"The position of the number "<<key<<" is "<<index + 1<<endl;
    }
    return 0;
}

int linearSearch(int array[], int n, int key){
    for(int i=0;i<n;i++){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}