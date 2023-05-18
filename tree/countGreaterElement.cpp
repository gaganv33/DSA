#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}	
	map<int, int> m;
	for(int i = 0; i < n; i++){
		m[arr[i]]++;
	}
	vector<int> a;
	for(int i = 0; i < n; i++){
		auto it = m.find(arr[i]);
		it++;
		int count = 0;
		while(it != m.end()){
			count = count + (*it).second;
			it++;			
		}
		a.push_back(count);
	}
	for(auto x : a){
		cout << x << " ";
	}
	return 0;
}