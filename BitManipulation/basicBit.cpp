#include<iostream>
#include<climits>
using namespace std;

int getBit(int n, int pos);
int setBit(int n, int pos);
int clearBit(int n, int pos);
int updateBit(int n, int pos, int value);

int main(){
    int n, pos, value;
    cin >> n;
    cin>> pos;
    cin >> value;
    cout<<getBit(n, pos) << " "<< setBit(n, pos) << " "<< clearBit(n, pos) << " "<< updateBit(n , pos, value)<<endl;

    return 0;
}

int getBit(int n, int pos){
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos){
    return (n | (1 << pos));
}
int clearBit(int n, int pos){
    int mask = ~(1 << pos);
    return (n & mask);
}
int updateBit(int n, int pos, int value){
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value < pos));
}