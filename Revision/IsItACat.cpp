#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		string s;
		cin >> n >> s;
		
		string t = "";
		for(auto x : s) {
			t += char(tolower(x));
		}
		string a = "";
		a += t[0];
		int j = 0;
				
		for(int i = 1; i < n; i++) {
			if(a[j] == t[i]) {
				continue;
			}
			else {
				a.push_back(t[i]);
				j++;
			}
		}
		
		
		if(a == "meow") {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}
	
	return 0;
}