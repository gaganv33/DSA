#include<bits/stdc++.h>
using namespace std;

int main(){
	string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	int n;
	cin >> n;
	string ans = "3.";
	for(int i = 0; i < n; i++){
		ans += pi[i + 2];
	}
	cout << ans << endl;
	return 0;
}