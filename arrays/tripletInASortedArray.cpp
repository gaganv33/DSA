#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	int l = 0;
	int h = n - 1;
	int sum = 0;
	
	while(l < h){
		sum = v[l] + v[h];
		int res = INT_MAX;
		for(int i = 0; i < n; i++){
			if(i != l && i != h){
				sum += v[i];
				if(sum == k){
					cout << "True" << endl;
					return 0;
				}
				res = min(res, sum);
				sum -= v[i];
			}
		}
		if(res < k){
			l++;
		}
		else{
			h--;
		}
	}
	cout << "False" << endl;
	return 0;
}