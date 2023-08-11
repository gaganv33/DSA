#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k, h;
		vector<int> v;
		cin >> n >> m >> k >> h;
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);		                    	
		}
		int ct = 0;
		for(int i = 0; i < n; i++){
			int diff = abs(h - v[i]);
			if(diff != 0 && (diff % k) == 0){
				int val = diff / k;
				if(val >= 1 && val <= (m - 1)){
			        	ct++;
				}
			}
		}
		cout << ct << endl;
	}
	return 0;
}