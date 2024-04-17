#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

bool check(vector<int> &a) {
	int n = a.size();
	for(int i = 0; i < n - 1; i++) {
		if(a[i] >= a[i + 1]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		vector<int> a;
		cin >> n;
		
		for(int i = 0; i < n; i++) {
			int value;
			cin >> value;
			a.push_back(value);
		}
		
		if(a[0] == 1) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}