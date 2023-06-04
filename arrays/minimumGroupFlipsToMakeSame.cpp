#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	vector<vector<int>> m;
	vector<vector<int>> p;
	int count = 0;
	int start;
	
	// Counting Total number of zero groups
	for(int i = 0; i < n; i++){
		if(v[i] == 0 && count == 0){
			start = i;
			count++;
		}
		else if(v[i] != 0 && count != 0){
			vector<int> b = {start, i - 1};
			p.push_back(b);
			count = 0;				
		}	
	}
	if(v[n - 1] == 0){
		vector<int> b = {start, n - 1};
		p.push_back(b);
	}
	
	// Counting total number of one groups
	count = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == 1 && count == 0){
			start = i;
			count++;
		}
		else if(v[i] != 1 && count != 0){
			vector<int> b = {start, i - 1};
			m.push_back(b);
			count = 0;			
		}
	}
	if(v[n - 1] == 1){
		vector<int> b = {start, n - 1};
		m.push_back(b);
	}
	if(m.size() > p.size()){
		for(auto x : p){
			cout << "From " << x[0] << " to " << x[1] << endl;
		}
	}
	else if(p.size() > m.size()){
		for(auto x : m){
			cout << "From " << x[0] << " to " << x[1] << endl;
		}
	}
	else{
		for(auto x : m){
			cout << "From " << x[0] << " to " << x[1] << endl;
		}
		cout << "OR" << endl;
		for(auto x : p){
			cout << "From " << x[0] << " to " << x[1] << endl;
		}
	}
	return 0;
}