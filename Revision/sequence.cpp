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
		vector<int> ans;
		ans.push_back(v[0]);
		if(n > 1){
			bool index = false;
			int i = 1;
			while(i < n){
				if(index){
					ans.push_back(v[i]);
					i++;
					index = false;
				}
				else{
					if(ans[ans.size() - 1] != 1){
						ans.push_back(1);
					}
					index = true;
				}
			}
		}
		cout << ans.size() << "\n";
		for(auto x : ans){
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}