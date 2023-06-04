#include<bits/stdc++.h>
using namespace std;

// Find the maximum sum of k consecutive elements
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int curr = 0;
	for(int i = 0; i < k; i++){
		curr += v[i];
	}
	int res = curr;
	for(int i = k; i < n; i++){
		curr = curr + v[i] - v[i - k];
		res = max(res, curr);
	}
	cout << res << endl;
	return 0;
}