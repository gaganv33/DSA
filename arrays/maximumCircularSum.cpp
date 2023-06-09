#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}                  
	
	int res = v[0]; 	
	int max_val = v[0];
	for(int i = 1; i < n; i++){
		max_val = max(max_val + v[i], v[i]);
		res = max(res, max_val);
	}

	int min_val = v[0];
	int temp = v[0];	
	for(int i = 1; i < n; i++){
		temp = min(temp + v[i], v[i]);
		min_val = min(min_val, temp);
	}
		
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];	
	}
	
	if(min_val < 0 && sum != min_val){
		sum = max(sum, sum - min_val);
		res = max(res, sum);
	}
	else{
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}