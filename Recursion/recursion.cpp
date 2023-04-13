#include<iostream>
#include<string.h>
using namespace std;

int power(int n, int p);
int factorial(int n);
int fibonacci(int n);
bool sorted(int arr[], int n);

int main(){
    cout<<"n raised to power"<<endl;
    int n,p;
    cin>>n>>p;
    cout<<power(n, p)<<endl;
    cout<<"factorial"<<endl;
    cin>>n;
    cout<<factorial(n)<<endl;
    cout<<"finonaccci"<<endl;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    cout<<"array sorted or not"<<endl;
    int arr[5] = {5, 6, 8, 9, 21};
    cout<<sorted(arr, 5)<<endl;

    return 0;
}

int power(int n, int p){
    if(p==0){
        return 1;
    }
    return n * power(n, p -1);
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n- 1);
}
int fibonacci(int n){
    if(n == 0 || n==1){
        return n;
    }
    return (fibonacci(n-1) + fibonacci(n-2));
}

bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool value = (arr[0] <= arr[1]);
    return (value && sorted(arr, n - 1));
}