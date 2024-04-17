#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int z = 0; z < t; z++) {
		int n;
		string s;
		cin >> n >> s;
		
		int i = 0;
		int j = n - 1;
		
		while(i < n && s[i] == 'W') {
			i++;
		}
		
		while(j >= 0 && s[j] == 'W') {
			j--;
		}
		
		cout << (j - i + 1) << endl;
	}
	
	return 0;
}