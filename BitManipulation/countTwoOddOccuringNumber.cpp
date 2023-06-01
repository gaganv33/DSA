#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int x = v[0];
	for(int i = 1; i < n; i++){
		x = x ^ v[i];
	}
	int k = (x & (~(x - 1)));
	int res1 = 0;
	int res2 = 0;
	for(int i = 0; i < n; i++){
		if(v[i] & k == 1){
			res1 = res1 ^ v[i];
		}
		else{
			res2 = res2 ^ v[i];
		}
	}
	cout << res1 << " " << res2 << endl;
	return 0;
}