#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	for(int i = 1; i < n; i++){
		a[i]+=a[i - 1];
		b[i]+=b[i - 1];
	}
	int m;
	cin >> m;
	while(m--){
		int t, l ,r;
		cin >> t >> l >> r;
		l--;
		r--;
		if(t == 1){
			if(l == 0){
				cout << a[r] << "\n";
			}
			else{
				cout << a[r] - a[l - 1] << "\n";
			}
		}
		else{
			if(l == 0){
				cout << b[r] << "\n";
			}
			else{
				cout << b[r] - b[l - 1] << "\n";
			}
		}
	}
	return 0;
}