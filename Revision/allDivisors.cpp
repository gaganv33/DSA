#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n);

int main(){
	int n;
	cin >> n;
	printDivisors(n);
	return 0;	
}

void printDivisors(int n){
	if(n == 1){
		return;
	}
	int i;
	for(i = 1; i * i <= n; i++){
		if(n % i == 0){
			cout << i << " ";
		}
	}
	for( ; i >= 1; i--){
		if(n % i == 0){
			cout << (n / i) << " ";
		}
	}
	return;
}