#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++){
		m[arr[i]]++;
	}	
	vector<vector<pair<int, int>>> res;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int index = m[arr[i]];
		if(index != -1){
			v.push_back({arr[i], index});
			m.erase(arr[i]);
		}
	}
	int max_value = INT_MIN;
	int min_value = INT_MAX;
	for(const auto &x : v){
		max_value = max(max_value, x.second);
		min_value = min(min_value, x.second);
	}	
	int value = max_value - min_value;
	for(int i = 0; i <= value; i++){
		vector<pair<int, int>> a;
		res.push_back(a);
	}
	for(auto x : v){
		int index = x.second - min_value;
		res[index].push_back(x);
	}
	vector<int> ans;
	for(int i = value; i >= 0; i--){
		for(auto x : res[i]){
			for(int j = 0; j < x.second; j++){
				ans.push_back(x.first);
			}
		}		
	}
	for(auto x : ans){
		cout << x << " ";
	}
	return 0;
}