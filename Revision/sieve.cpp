#include<bits/stdc++.h>
using namespace std;

vector<bool> v(90000001, 1);
vector<int> ans;

void sieve(){
	v[0] = v[1] = 0;
	for(int i = 2; i * i < 90000001; i++){
		if(v[i]){
			for(int j = i * i; j < 90000001; j += i){
				v[j] = 0;
			}
		}
	}

	for(int i = 0; i < 90000001; i++){
		if(v[i]){
			ans.push_back(i);
		}
	}
}

int main(){
	sieve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << ans[n - 1] << endl;
	}
	return 0;
}