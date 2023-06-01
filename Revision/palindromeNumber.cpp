#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m = n;
	int rev = 0;
	while(m > 0){
		rev = (rev * pow(10, 1)) + (m % 10);
		m = m / 10;
	}
	cout << rev << endl;
	if(rev == n){
		cout << "Yes" << endl;
		return 0;
	}                	
	cout << "No" << endl;
	return 0;
}