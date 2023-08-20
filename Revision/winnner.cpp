#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string, pair<int, int>> m;
	int time = 1;
	while(n--){
		string name;
		int score;
		cin >> name;
		cin >> score;
		m[name].first += score;
		m[name].second = time;
		time++;
	}
	string ans;
	time = 0;
	int score = -1001;
	for(auto x : m){
		if(x.second.first >= score && x.second.second < time){
	        	ans = x.first;
			score = x.second.first;
			x.second.second = time;
		}
	}
	cout << ans << "\n";
	return 0;
}