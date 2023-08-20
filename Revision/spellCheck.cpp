#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	unordered_map<char, int> m; 
	m['T']++;
	m['i']++;
	m['m']++;
	m['u']++;
	m['r']++;
	while(t--){
		unordered_map<char, int> p = m;
		int n;
		cin >> n;
		string str;
		cin >> str;
		bool found = false;
		for(int i = 0; i < n; i++){
			if(p.find(str[i]) == p.end()){
				cout << "NO\n";
				found = true;
				break;
			}
			else{
				p[str[i]]--;
				if(p[str[i]] == 0){
					p.erase(str[i]);
				}
			}
		}
		if(!found && p.size() == 0){
			cout << "YES\n";
		}
		else if(!found && p.size() != 0){
			cout << "NO\n";
		}
	}
	return 0;
}