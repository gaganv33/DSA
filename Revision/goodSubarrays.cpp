#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		vector<int> v(n + 1, 0);
		for(int i = 1; i <= n; i++){
			v[i] = (str[i - 1] - '0' - 1);
		}
		for(int i = 1; i <= n; i++){
			v[i] += v[i - 1];
		}
		map<int, int> m;
		for(int i = 0; i <= n; i++){
			m[v[i]]++;
		}
		long long ans = 0;
		for(auto x : m){
			if(x.second > 1){
				ans += x.second * (x.second - 1) / 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}