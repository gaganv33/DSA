#include<bits/stdc++.h>
using namespace std;

bool foundPages(vector<int> v, int n, int k, int val);

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int max_el = *max_element(v.begin(), v.end());
	int sum = accumulate(v.begin(), v.end(), 0);
	
	int low = max_el;
	int high = sum;
	int res = -1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(foundPages(v, n, k, mid)){
			res = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;			
		}		
	}
	cout << res << endl;
	return 0;
}

bool foundPages(vector<int> v, int n, int k, int val){
	int ct = 1;
	int sum = v[0];
	for(int i = 1; i < n; i++){
		if((sum + v[i]) <= val){
			sum += v[i];
		}
		else{
			ct++;
			sum = v[i];
		}
	}
	return (ct <= k);
}