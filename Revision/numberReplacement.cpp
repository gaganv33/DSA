#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];			
		}
		string str;
		cin >> str;
		map<int, char> m;
		bool found = false;
		for(int i = 0; i < n; i++){
			auto it = m.find(a[i]);
			if(it == m.end()){
				m.insert({a[i], str[i]});
			}				
			else{
				pair<int, char> p = *it;
				if(p.second != str[i]){
					found = true;
					cout << "NO\n";
					break;
				}
			}		
		}
		if(!found){
			cout << "YES\n";
		}
	}
	return 0;
}