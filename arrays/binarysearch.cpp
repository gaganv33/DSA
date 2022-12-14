#include<iostream>
using namespace std;

int binarySearch(int array[], int n, int key);
int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int key;
    cin>>key;

    int index = binarySearch(array, n, key);
    if(index==-1){
        cout<<"The number "<<key<<" not present in the array of integers."<<endl;
    }
    else{
        cout<<"The position of the number "<<key<<" is "<<index + 1<<endl;
    }
    return 0;
}

int binarySearch(int array[], int n, int key){
    int s = 0;
    int e = n;
    while(s <= e){
        int mid = (s + e) / 2;
        if(array[mid] == key){
            return mid;
        }
        else if(array[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}