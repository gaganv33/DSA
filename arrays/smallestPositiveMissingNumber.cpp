#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	/*
	// Using Auxiliary Space	
	map<int, int> m;
	for(int i = 0; i < n; i++){
		if(v[i] > 0){
			m[v[i]]++;
		}
	}
	int index = 1;
	for(auto x : m){
		if(x.first != index){
			cout << index << endl;
			return 0;
		}
		index++;
	}
	int max_el = *max_element(v.begin(), v.end());
	if(max_el <= 0){
		cout << 1 << endl;
		return 0;
	}
	cout << max_el + 1 << endl;	
	*/
	
	// Without using Auxiliary Space
	for(int i = 0; i < n; i++){
		int correctIndex = v[i] - 1;
		while(correctIndex >= 0 && correctIndex < n && v[i] != v[correctIndex]){
			swap(v[i], v[correctIndex]);
			correctIndex = v[i] - 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(v[i] != (i + 1)){
			cout << (i + 1) << endl;
			return 0;
		}
	}
	cout << (n + 1) << endl;	                         
	return 0;
}