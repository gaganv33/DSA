#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for(int i = 0; i < n; i++){
		int f, s;
		cin >> f >> s;
		v[f - 1].push_back(s);
	}
	for(int i = 0; i < n; i++){
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	int answer = INT_MIN;
	pair<int, int> val = make_pair(0, 0);
	for(int i = 0; i < n; i++){
		vector<int> x = v[i];
		if(x.size() >= 1 && x[0] > val.second){
			val.first = i + 1;
			val.second = x[0];
		}
		if(x.size() > 1){
			answer = max(answer, x[0] + (x[1] / 2));
		}
	}
	for(int i = 0; i < n; i++){
		if(v[i].size() >= 1 && (i + 1) != val.first){
			answer = max(answer, val.second + v[i][0]);
		}
	}
	cout << answer << "\n";
	return 0;
}
