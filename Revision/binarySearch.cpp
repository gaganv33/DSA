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
		int low = 0;
		int high = n - 1;
		bool found = false;
		while(low <= high){
			int mid = low + (high - low) / 2;
			if(v[mid] == k){
				cout << "YES" << endl;
				found = true;
				break;
			}
			else if(v[mid] < k){
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		if(!found){
			cout << "NO" << endl;
		}

	}
	return 0;
}