#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int res = -1;
	int l = 0;
	int h = n - 1;

	while(l <= h){
		int mid = l + (h - l) / 2;
		if(v[mid] == 0){
			l = mid + 1;
		} 
		else if(v[mid] == 1){
			if(mid == 0 || v[mid] != v[mid - 1]){
				res = mid;
				break;
			}
			else{
				h = mid - 1;
			}
		}
	}
	if(res == -1){
		cout << 0 << endl;
		return 0;
	}
	cout << (n - res) << endl;
	return 0;
}