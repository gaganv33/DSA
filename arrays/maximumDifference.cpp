#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int min_val = v[0];
	int res = INT_MIN;
	for(int i = 1; i < n; i++){
		res = max(res, v[i] - min_val);		
		min_val = min(min_val, v[i]);
	}	
	cout << res << endl;
	return 0;
}