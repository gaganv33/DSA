#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		int index = 0;
		bool found = false;
		string ans = "vika";
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(v[j][i] == ans[index]){
					index++;
					break;
				}
			}
			if(index == 4){
				cout << "YES" << "\n";
				found = true;
				break;
			}
		}
		if(!found){
			cout << "NO\n";
		}
	}
	return 0;
}