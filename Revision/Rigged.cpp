#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int z = 0; z < t; z++) {
		int n;
		cin >> n;
		
		vector<int> s, e;
		
		for(int i = 0; i < n; i++) {
			int val1, val2;
			cin >> val1 >> val2;
			s.push_back(val1);
			e.push_back(val2);
		}
		
		int max_value = INT_MIN;
		
		for(int i = 1; i < n; i++) {
			if(s[i] >= s[0]) {
				max_value = max(max_value, e[i]);
			}
		}
		
		if(max_value < e[0]) {
			cout << s[0] << endl;
		}
		else {
			cout << -1 << endl;
		}

	}
	
	return 0;
}