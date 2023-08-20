#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b, c;
		cin >> a >> b >> c;
		int k = c / 2;
		a = a + c - k;
		b = b + k;
		if(a > b){
			cout << "First\n";
		}
		else{
			cout << "Second\n";
		}
	}
	return 0;
}