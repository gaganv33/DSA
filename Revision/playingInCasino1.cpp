#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v;
		for(int i = 0; i < n; i++){
			vector<int> a;
			for(int j = 0; j < m; j++){
				int val;
				cin >> val;
				a.push_back(val);
			}
			v.push_back(a);
		}
		int total = 0;
		if(n != 1){
			for(int i = 0; i < n - 1; i++){
				for(int j = i + 1; j < n; j++){
					for(int k = 0; k < m; k++){
						total += abs(v[i][k] - v[j][k]);
					}
				}
			}
		}
	
		cout << total << endl;
	}
	return 0;
}