#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unordered_set<int> s;
	for(int i = 0; i < n; i++){
		s.insert(arr[i]);
	}
	for(int i = 0; i < n; i++){
		auto it = s.find(arr[i]);
		if(it != s.end()){
			cout << (*it) << " ";
			s.erase(it);
		}
	}
	return 0;                 
}