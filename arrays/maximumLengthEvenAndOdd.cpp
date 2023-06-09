#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = 1;
	int count = 1;
	int alt = v[0] % 2;
	
	for(int i = 1; i < n; i++){
		if((alt && (v[i] % 2 == 0)) || (!alt && (v[i] % 2 != 0))){
			count++;
			res = max(res, count);
		}
		else{
			count = 1;
		}
		alt = v[i] % 2;
	}
	cout << res << endl;
	return 0;
}