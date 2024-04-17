#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n, k;
		cin >> n >> k;
		
		string a = "";
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {
				a += char('a' + j);
			}
		}
		cout << a << endl;
	}
	return 0;
}