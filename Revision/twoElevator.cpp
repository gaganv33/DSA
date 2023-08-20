#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			cout << 1 << endl;
		}
		else{
			if(c == 1){
				if((b - c) < (a - 1)){
					cout << 2 << endl;
				}
				else if((b - c) == (a - 1)){
					cout << 3 << endl;
				}
				else{
		                	cout << 1 << endl;
				}
			}
			else{
				int diff1 = a - 1;
				int diff2 = abs(b - c) + (c - 1);
				if(diff1 < diff2){
					cout << 1 << endl;
				}
				else if(diff2 < diff1){
					cout << 2 << endl; 
				}
				else{
					cout << 3 << endl;
				}
			}
		}
	}
	return 0;
}