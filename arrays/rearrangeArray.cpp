#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	 Given an array of size N where array element is in the range from 0 to (n - 1).
	 Rearrage the given array so that the transformed array v^T becomes v[v[i]]
	*/
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	for(int i = 0; i < n; i++){
		v[i] += ((v[v[i]] % n) * n);
	}
	for(int i = 0; i < n; i++){
		v[i] /= n;
	}
	for(auto x : v){
		cout << x << " ";
	}
	return 0;
}
	