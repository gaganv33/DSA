#include<iostream>
using namespace std;
struct point{
    int x;
    int y;
};
void Print(point &a){
    cout<<"In the function Print"<<endl;
    cout<<a.x<<" "<<a.y;
}
int main(){
    struct point a;
    cin>>a.x>>a.y;
    Print(a);
}