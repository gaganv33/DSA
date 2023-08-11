#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, pair<int , int>> p1, pair<int, pair<int, int>> p2){
	if(p1.second.second > p2.second.second){
		return true;
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, pair<int, int>>> v;
		for(int i = 0; i < n; i++){
			int first, second;
			cin >> first >> second;
			v.push_back(make_pair(i, make_pair(first, second)));	
		}
		sort(v.begin(), v.end(), myCmp);
		for(auto x : v){
			if(x.second.first <= 10){
				cout << x.first + 1 << endl;
				break;
			}
		}
		

	}
	return 0;
}
