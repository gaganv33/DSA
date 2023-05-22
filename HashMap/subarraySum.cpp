#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	long long int arr[n];
	for(long long int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unordered_map<long long int, pair<long long int, long long int>> m;
	for(long long int i = 0; i < n; i++){
		auto it = m.find(arr[i]);
		if(it == m.end()){
			m.insert({arr[i], {i, INT_MIN}});			
		}
		else{
			(*it).second.second = i;
		}
	}
	long long int max_sum = INT_MIN;
	for(auto x : m){
		if(x.second.second == INT_MIN){
			max_sum = max(max_sum, x.first);
		}
		else{
			long long int sum = 0;
			for(int j = x.second.first; j <= x.second.second; j++){
				sum = sum + arr[j];
			}
			max_sum = max(max_sum, sum);
		}
	}
	cout << max_sum << endl;
	return 0;
}