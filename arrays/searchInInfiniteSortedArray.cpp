#include<bits/stdc++.h>
using namespace std;

int main(){
	// Unbounded Binary Search
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	if(v[0] == k){
		cout << 0 << endl;
		return 0;
	}	
	int i = 1;
	while(i < n){
		if(v[i] >= k){
			break;
		}
		i = i * 2;
	}
	if(v[i] == k){
		cout << i << endl;
		return 0;
	}
	else if(v[i] < k){
		cout << -1 << endl;
		return 0;
	}
	int l = (i / 2) + 1;
	int h = i - 1;
	int res = -1;
	while(l <= h){
		int mid = l + (h - l) / 2;
		if(v[mid] > k){
	        	h = mid - 1;
		}
		else if(v[mid] < k){
			l = mid + 1;
		}
		else{
			if(mid == 0 || v[mid] != v[mid - 1]){
		        	res = mid;
				break;
			}
			else{
				h = mid - 1;
			}
		}
	}
	cout << res << endl;
	return 0;
}
