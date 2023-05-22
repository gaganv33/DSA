#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	set<int> s;
	int res[n];
	for(int i = 0; i < n; i++){
		auto it = s.upper_bound(arr[i]);
		if(it == s.end()){
			res[i] = -1;	
		}
		else{
			res[i] = (*it);
		}
		s.insert(arr[i]);
	}
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	return 0;
}