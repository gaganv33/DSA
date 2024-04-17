#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		cin >> n;
		string a, b, c;
		cin >> a >> b >> c;
		
		bool check = true;
		
		for(int i = 0; i < n; i++) {
			if(a[i] != c[i] && b[i] != c[i]) {
				check = false;
				break;
			}
		}
		
		if(!check) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		
	}
	return 0;
}