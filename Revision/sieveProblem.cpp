#include<Bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<bool> v(n + 1, true);
	for(int i = 2; i * i <= n; i++){
		if(v[i] == true){
			for(int j = i * i; j <= n; j = j + i){
				v[j] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(v[i])
			cout << i << " ";
	}
	return 0;
}