#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int prefixMax[n];
	int suffixMax[n];
	
	prefixMax[0] = v[0];
	for(int i = 1; i < n; i++){
		prefixMax[i] = max(prefixMax[i - 1], v[i]);
	}
	
	suffixMax[n - 1] = v[n - 1];
	for(int i = n - 2; i >= 0; i--){
		suffixMax[i] = max(v[i], suffixMax[i + 1]);
	}

	int res = 0;
	for(int i = 1; i <= n - 2; i++){
		res = res + (min(prefixMax[i], suffixMax[i]) - v[i]);
	}
	cout << res << endl;
		
	return 0;
}