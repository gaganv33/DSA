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
		if(n != v[0]){
			cout << "NO\n";
		}
		else{
			vector<int> a(v[0]);
			for(int i = 0; i < n; i++){
				a[v[i] - 1]++;
			}
			for(int i = v[0] - 2; i >= 0; i--){
				a[i] = a[i] + a[i + 1];
			}
			if(n != a.size()){
				cout << "NO\n";
			}
			else{
				bool found = false;
				for(int i = 0; i < n; i++){
					if(v[i] != a[i]){
						cout << "NO\n";
						found = true;
						break;
					}
				}
				if(!found){
					cout << "YES\n";
				}
			}
		}
	}
	return 0;
}