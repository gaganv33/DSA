#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		cin >> n;
		
		if(n % 3 == 0) {
			cout << "Second" << endl;
		}
		else {
			cout << "First" << endl;
		}
	}
	
	return 0;
}