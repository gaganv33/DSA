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
	int res = -1;
	while(l <= h){
		int mid = l + (h - l) / 2;
		if(v[mid] == k){
			if(mid == 0 || v[mid] != v[mid - 1]){
				res = mid;
				break;
			}
			else{
				h = mid - 1;
			}
		}
		else if(v[mid] > k){
			h = mid - 1;
		}
		else if(v[mid] < k){
			l = mid + 1;
		}
	}
	cout << res << endl;
	return 0;
}