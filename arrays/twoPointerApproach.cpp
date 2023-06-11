#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	Find if there is a pair with sum k in a sorted array
	*/
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int l = 0;
	int h = n - 1;
	int sum = v[l] + v[h];
	while(l < h){
		if(sum == k){
			cout << "True" << endl;
			return 0;
		}
		else if(sum < k){
			sum = sum - v[l];
			l++;
			sum = sum + v[l];
		}
		else{
			sum = sum - v[h];
			h--;
			sum = sum + v[h];
		}
	}
	cout << "False" << endl;
	return 0;
}