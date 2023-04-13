#include<iostream>
#include<string.h>
using namespace std;
class Test{
    public:
        int x, y;
        Test(int a = 0, int b = 0){
            x = a;
            y = b;
            cout<<"Constructor Called"<<endl;
        }
        ~Test(){
            cout<<"Destructor Called"<<endl;
        }
        Print(){
            cout<<x<<" "<<y<<endl;
        }
};
class SP{
    public:
        Test *ptr;
        SP(Test *p=NULL){ptr = p;}
        ~SP() {delete ptr;}
        Test &operator *(){ return *ptr; }
        Test *operator->(){ return ptr; }
};
class NewSP{
    int *ptr;
    public:
        NewSP(int *p = NULL){ ptr = p; }
        ~NewSP() { delete ptr; }
        int &operator *() { return *ptr; }
};
int main(){
    // cout<<"Main begins"<<endl;
    // {
    //     SP sp(new Test(10, 20));
    //     cout<<sp->x<<endl;
    //     cout<<sp->y<<endl;
    //     sp->Print();

    //     // NewSP sp(new int(44));
    //     // cout<<&sp<<endl;
    // }
    // cout<<"Main ends"<<endl;
    // int a[][2] = {{1, 2}, {3, 4}};
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout<<a[i][j];
    //     }
    // }
    string s1 = "Hello";
    string s2 = "World";
    cout<<s1+s2<<endl;
    return 0;
}