#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int money = 3;
    int wrappers = 0;
    int chocolate = 0;
    for(int i=1; i<= money; i++){
        chocolate = chocolate + 1;
        wrappers = wrappers + 1;
    }
    while(wrappers >= 3){
        int new_chocolate = wrappers / 3;
        wrappers = (wrappers % 3) + new_chocolate;
        chocolate = chocolate + new_chocolate;
    }
    cout<<"Total number of chocolates are: "<<chocolate<<endl;
    return 0;
}

