#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int max_value = INT_MIN;
		int min_value = INT_MAX;
		for(int i = 0; i < n; i++){
			int val;
			cin >> val;
			max_value = max(max_value, val);
			min_value = min(min_value, val);
		}
		cout << (max_value - min_value) << "\n";
	}
	return 0;
}