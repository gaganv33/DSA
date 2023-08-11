#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	while(k--){
		int x;
		cin >> x;
		if(x > v[n - 1]){
			cout << n + 1 << endl;
		}
		else{
			int l = -1;
			int h = n;
			while(h > l + 1){
				int m = l + (h - l) / 2;
				if(v[m] >= x){
					h = m;
				}
				else{
					l = m;
				}				
			}
			cout << h + 1 << endl;
		}
	}
	return 0;
}