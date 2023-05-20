#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unordered_map<string, int> m;
	for(int i = 0; i < n; i++){
		m[arr[i]]++;
	}
	string res;
	int max_freq = 0;
	for(auto x : m){
		if(x.second > max_freq){
			max_freq = x.second;
			res = x.first;
		}
		else if(x.second == max_freq && x.first < res){
			res = x.first;
		}
	}
	cout << res << endl;
	return 0;
}