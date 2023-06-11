#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n < 0){
		cout << "Not defined" << endl;
		return 0;
	}                                     	
	else if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	
	int ans = -1, l = 1, h = n;
	while(l <= h){
		int mid = l + (h - l) / 2;
		int mSq = mid * mid;
		if(mSq == n){
			cout << mid << endl;
			return 0;
		}
		else if(mSq > n){
			h = mid - 1;
		}
		else{
			l = mid + 1;
			ans = mid;
		}
	}	
	cout << ans << endl;
	return 0;
}