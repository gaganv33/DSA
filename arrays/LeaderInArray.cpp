#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}		
	int leader = v[n - 1];
	cout << leader << " ";
	for(int i = n - 2; i >= 0; i--){
		if(leader < v[i]){
			leader = v[i];
			cout << v[i] << " ";
		}
	}
	return 0;
}