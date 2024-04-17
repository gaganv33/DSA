#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<vector<char>> v;
		for(int i = 0; i < 8; i++){
			vector<char> b(8);
			for(int j = 0; j < 8; j++){
				cin >> b[j];
			}
			v.push_back(b);
		}
		string ans = "";
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(v[j][i] != '.'){
					ans += v[j][i];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}