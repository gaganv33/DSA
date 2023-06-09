#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = INT_MIN;
	int sum = 0;
	
	for(int i = 0; i < k; i++){
		sum += v[i];
	}	
	res = max(res, sum);	
	for(int i = k; i < n; i++){
		sum = sum - v[i - k] + v[i];
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}