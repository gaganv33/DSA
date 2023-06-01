#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;
	if(d >= n){
		d = d - n;
	}
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}	
	vector<int> temp(d);
	for(int i = 0; i < d; i++){
		temp[i] = v[i];
	}
	for(int i = d; i < n; i++){
		v[i - d] = v[i];
	}
	for(int i = n - d; i < n; i++){
		v[i] = temp[i - n + d];
	}
	for(auto x : v){
		cout << x << " ";
	}
	return 0;
}