#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int a[m], b[n];
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	int i = 0;
	int j = 0;
	while(i < m && j < n){
		if(i > 0 && a[i] == a[i - 1]){
			i++;
			continue;
		}
		if(a[i] > b[j]){
			j++;
		}
		else if(a[i] < b[j]){
			i++;
		}
		else{
			cout << a[i] << " ";
			i++;
			j++;
		}
	}
	return 0;
}