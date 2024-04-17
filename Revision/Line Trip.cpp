#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a;
		a.push_back(0);
		
		for(int i = 0; i < n; i++) {
			int value;
			cin >> value;
			a.push_back(value);
		}
		
		int result = (x - a[n]) * 2;
		for(int i = 0; i < n; i++) {
			result = max(result, a[i + 1] - a[i]);
		}
		
		cout << result << endl;
		
	}
	
	return 0;
}