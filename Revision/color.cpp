#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		string f, s;
		cin >> f >> s;
		bool found = true;
		for(int i = 0; i < n; i++){
			if((f[i] == 'R' && s[i] != 'R') || (f[i] != 'R' && s[i] == 'R')){
				cout << "NO\n";
				found = false;
				break;
			}
		}
		if(found){
			cout << "YES\n";
		}
	}
	return 0;
}