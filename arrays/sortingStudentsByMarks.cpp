#include<bits/stdc++.h>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2){
	return p1.second > p2.second;
}

int main(){
	int n;
	cin >> n;
	int roll[n], marks[n];
	for(int i = 0; i < n; i++){
		cin >> roll[i] >> marks[i];
	}
	vector<pair<int, int>> v;
	for(int i = 0; i< n; i++){
		v.push_back({roll[i], marks[i]});
	}
	sort(v.begin(), v.end(), myCompare);
	for(auto x : v){
		cout << x.first << " " << x.second << endl;
	}	
	return 0;
}