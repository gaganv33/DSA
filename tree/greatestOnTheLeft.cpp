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
	for(int i = 0; i < n; i++){
		if(i == 0){
			cout << -1 << " ";
		}
		else{
			auto it = s.upper_bound(arr[i]);
			if(it == s.end()){
				cout << -1 << " ";
			}
			else{
				if(*it == arr[i]){
					cout << -1 << " ";
				}
				else{
					cout << *it << " ";
				}
			}
		}
		s.insert(arr[i]);
	}
	return 0;
}