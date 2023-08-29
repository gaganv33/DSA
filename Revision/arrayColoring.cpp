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
		unordered_map<int, vector<int>> m;
		for(int i = 0; i < n; i++){
			m[v[i] % 2].push_back(v[i]);
		}
		if(m[0].size() != 0 && m[1].size() != 0){
			if(m[1].size() % 2 == 0){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else if(m[0].size() == 0 && m[1].size() != 0){
			if(m[1].size() % 2 == 0){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else if(m[0].size() != 0 && m[1].size() == 0){
			cout << "YES\n";
		}
	}
	return 0;
}