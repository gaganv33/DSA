#include<bits/stdc++.h>
using namespace std;

int find2Power(int n);
int totalBits(int n);

int main(){
	int n;
	cin >> n;
	int res = totalBits(n);
	cout << res << endl;
	return 0;
}

int find2Power(int n){
	int x = 0;
	while((1 << x) <= n){
		x++;
	}	
	return x - 1;
}

int totalBits(int n){
	if(n == 0){
		return 0;
	}
	int x = find2Power(n);
	int a = (1 << (x - 1)) * x;
	int b = n - (1 << x) + 1;
	int rest = n - (1 << x);
	return a + b + totalBits(rest);
}