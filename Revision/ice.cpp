#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long int n;
		cin >> n;
		unsigned long long int num = (1 + sqrt(1 + (8 * n))) / 2;
		unsigned long long int value = (num * (num - 1)) / 2;
		if(value == n){
			cout << num << "\n";
		}
		else{
			num = num + (n - value);
			if(value + (n - value) < n){
				cout << num + 2 << "\n";
			}
			else{
				cout << num << "\n";
			}
		}
	}
	return 0;
}