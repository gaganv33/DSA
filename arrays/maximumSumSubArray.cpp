#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = v[0];
	int maxEnding = v[0];
	for(int i = 1; i < n; i++){
		maxEnding = max(maxEnding + v[i], v[i]);
		res = max(res, maxEnding);
	}
	cout << res << endl;
	return 0;
}