#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if(v.size() == 1 || v.size() == 2){
			cout << 0 << "\n";
		}
		else if(v.size() == 3){
			cout << (v[n - 1] - v[0]) << "\n";
		}
		else{
			cout << (v[n - 1] - v[0] + v[n - 2] - v[1]) << "\n";
		}
	}
	return 0;
}