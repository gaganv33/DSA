#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = v[0];
	for(int i = 1; i < n; i++){
		res = res ^ v[i];
	}
	cout << res << endl;
	return 0;
}