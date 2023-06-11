#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	int res_first = -1;
	int res_last = -1;
	
	int l = 0;
	int h = n - 1;
	
	// Calculating the first occurence index
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
				res_first = mid;
				break;
			}
			else{
				h = mid - 1;
			}
		}
	}
	
	// Calculating the last occurence index	
	l = 0;
	h = n - 1;
	while(l <= h){
		int mid = l + (h - l) / 2;
		if(v[mid] > k){
			h = mid - 1;
		}
		else if(v[mid] < k){
			l = mid + 1;
		}
		else{
			if(mid == n - 1 || v[mid] != v[mid + 1]){
				res_last = mid;
				break;
			}
			else{
				l = mid + 1;
			}
		}
	}
	if(res_first == -1){
		cout << 0 << endl;
		return 0;
	}	
	cout << (res_last - res_first + 1) << endl;
	return 0;
}