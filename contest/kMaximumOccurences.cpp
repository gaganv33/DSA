#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	vector<int> a;
	cin >> n >> k;
	
	for(int i = 0 ; i < n; i++) {
		int val;
		a.push_back(val);
	}
	long long mod = 1e9 + 7;
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		map<int, int> m;
		bool found = true;
		for(int j = i; j < n; j++) {
			m[a[j]]++;

			if(m[a[j]] != k && m[a[j]] != 0) found = false;
			if(!found) break;
			if(found) {
				ans = (ans + 1) % mod;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}