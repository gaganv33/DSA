#include<iostream>
using namespace std;
/*
QUESTION:
Isyana is given the number of visitors at her local theme park on N consecutive
days. The number of visitors on the i-th day is Vi

. A day is record breaking if it

satisfies both of the following conditions:
● The number of visitors on the day is strictly larger than the number of
visitors on each of the previous days.
● Either it is the last day, or the number of visitors on the day is strictly larger
than the number of visitors on the following day.
Note that the very first day could be a record breaking day!
*/
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i = 0; i<n;i++){
        cin>>array[i];
    }
    int counter = 0;
    if(n == 1){
        counter ++;
    }
    else{
        if(array[0] > array[1]){
            counter ++;
        }
        
        for(int i=1;i<n;i++){
            bool flag = true;
            for(int j=i-1;j>=0;j--){
                if(array[i] < array[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                if(i != (n - 1)){
                    if(array[i] < array[i - 1]){
                        flag = false;
                    }
                }
            }
            if(flag == true){
                counter ++;
            }
        }
    }
    cout<<"Counter Value is: "<<counter<<endl;
    return 0;
}