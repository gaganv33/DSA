#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	while(t--){
		int k;
		cin >> k;
		if(k < v[0]){
			cout << 0 << endl;
		}
		else{
			int l = -1;
			int h = n;
			while(l + 1 < h){
				int m = l + (h - l) / 2;
				if(v[m] <= k){
					l = m;
				}
				else{
					h = m;
				}
			}
			cout << l + 1 << endl;
		}                                           
	}
	return 0;
}