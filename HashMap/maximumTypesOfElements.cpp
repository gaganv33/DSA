#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int sz = (n / k);
	unordered_set<int> s;
	for(int i = 0; i < n; i++){
		s.insert(arr[i]);
	}
	int ct = s.size();
	
	if(ct >= sz){
		cout << sz << endl;
	}
	else{
		cout << ct << endl;
	}
	return 0;
}