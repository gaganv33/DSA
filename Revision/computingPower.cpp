#include<bits/stdc++.h>
using namespace std;

int PowerRec(int n, int k);
int PowerIter(int n, int k);

int main(){
	int n, k;
	cin >> n >> k;
	int res = PowerRec(n, k);
	cout << res << endl;
	res = PowerIter(n, k);
	cout << res << endl;
	return 0;	
}

int PowerRec(int n, int k){
	if(k == 0){
		return 1;
	}
	int val = PowerRec(n, k / 2);
	val = val * val;
	if(k % 2 == 0){
		return val;
	}
	else{
		return val * n;
	}
}

int PowerIter(int n, int k){
	int val = 1;
	while(k > 0){
		if(k % 2 != 0){
			val = val * n;
		}		
		n = n * n;
		k = k / 2;
	}
	return val;
}