#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int value;
		cin >> value;
		v.push_back(value);
	}
	unordered_set<int> s;
	for(int i = 0; i < n; i++){
		if(s.find(v[i]) == s.end()){
			s.insert(v[i]);
		}
		else{
			cout << v[i] << " ";
		}
	}	
	return 0;
}