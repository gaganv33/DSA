#include<iostream>
#include<vector>
using namespace std;

int main(){
	/*
	 Given an array of N positive integers. Fine thne maximum (j - i) subjected to the constraint of
	 v[j] >= v[i] and i <= j
	*/
	int n;	
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<int> pre_min(n);
	vector<int> suf_max(n);
	
	pre_min[0] = v[0];
	suf_max[n - 1] = v[n - 1];
	
	for(int i = 1; i < n; i++){
		pre_min[i] = min(pre_min[i - 1], v[i]);
	}
	
	for(int i = n - 2; i >= 0; i--){
		suf_max[i] = max(suf_max[i + 1], v[i]);
	}
	
	int i = 0;
	int j = 0;
	int res = 0;
	while(i < n && j < n){
		if(pre_min[i] <= suf_max[j]){
			res = max(res, (j - i));
			j++;
		}
		else{
			i++;
		}
	}                   
	cout << res << endl;
	return 0;
}