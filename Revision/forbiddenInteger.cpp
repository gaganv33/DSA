#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, x;
		cin >> n >> k >> x;
		vector<int> ans;
		while(n != 0 && k != 0){
			//cout << k << endl;
			if(k == x){
				k--;
				if(k == 0){
					break;
				}
			}
			int q = n / k;
			//if(q > 0){

				for(int i = 0; i < q; i++){
					ans.push_back(k);				
				}
				//if((q * k) == n){
				//	n = n - (q * k);
				//	break;
				//}
				n = n - (q * k);				
			//}
			k = n;
		}
		if(n == 0){
			cout << "YES" << endl;
			cout << ans.size() << endl;
			for(auto x : ans){
				cout << x << " ";
			}
			cout << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}