#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = abs(v[0] - v[n - 1]);
	for(int i = 0; i <= n - 2; i++){
		res = min(res, abs(v[i] - v[i + 1]));		
	}
	cout << res << endl;
	return 0;
}