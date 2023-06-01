#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i < n - 1; i++){
		if(v[i] < ans){
			break;
		}
		else{
			for(int j = i + 1; j < n; j++){
				if(v[j] < ans){
	                        	break;
				}
				else{
					ans = max(ans, (v[i] & v[j]));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}