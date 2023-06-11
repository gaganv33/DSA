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
	while(l <= h){
		int mid = l + (h - l) / 2;
		if(v[mid] == k){
			cout << mid << endl;
			return 0;
		}
		// Left part of the array is sorted
		else if(v[l] < v[mid]){
			if(v[l] <= k && v[mid] >= k){
				h = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		// Right part of the array is sorted
		else{
			if(v[mid] <= k && v[h] >= k){
				l = mid + 1;
			}
			else{
				h = mid - 1;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}