#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		string s;
		cin >> n >> s;
		
		int count = 0;

		for(int i = 0; i < n; i++) {
			if(s[i] == '.') {
				count++;
			}
		}
		
		bool check = false;
		for(int i = 0; i < n; i++) {
			if(s[i] == '.') {
				int j = 0;
				while(i < n && j < 3) {
					if(s[i] == '.') {
						j++;
						i++;
					}
					else {
						break;
					}
				}
				
				if(j == 3) {
					check = true;
					break;
				}
			}
		}
		if(check) {
			cout << 2 << endl;
		}
		else {
			cout << count << endl;
		}
	}
	
	return 0;
}