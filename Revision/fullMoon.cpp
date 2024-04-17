#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, p;
	cin >> n >> m >> p;
	if(m > n){
		cout << 0 << "\n";
	}
	else{
		int count = 1 + ((n - m) / p);
		cout << count << "\n";
	}
	return 0;
}