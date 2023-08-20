#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	
	string ans = "";
	int i = 0;
	int index = 1;
	while(i < n){
		ans += str[i];
		i += index;
		index++;
	}
	cout << ans << "\n";
	return 0;
}