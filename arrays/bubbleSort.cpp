#include<Iostream>
using namespace std;
void buubleSort(int array[], int n);
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    buubleSort(array, n);
    return 0;
}
void buubleSort(int array[], int n){
    int counter = 1;
    while(counter < n){
        for(int i=0; i< n - counter; i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        counter ++;
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}