#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	if(n == 2 || n == 1){
		cout << 0 << "\n";
	}
	else{
		sort(v.begin(), v.end());
		cout << min((v[n - 2] - v[0]), (v[n - 1] - v[1]));
	}
	return 0;
}