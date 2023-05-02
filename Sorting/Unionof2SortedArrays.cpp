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
	sort(a, a + m);
	sort(b, b + n);
	int i = 0;	
	int j = 0;
	while(i < m && j < m){
		if(i > 0 && a[i] == a[i - 1]){
			i++;
			continue;
		}
		if(j > 0 && b[j] == b[j - 1]){
			j++;
			continue;
		}
		if(a[i] < b[j]){
			cout << a[i] << " ";
			i++;
		}
		else if(b[j] < a[i]){
			cout << b[j]  << " ";
			j++;
		}
		else{
			cout << a[i] << " ";
			i++;
			j++;
		}
	}
	while(i < m){
		if(i > 0 && a[i] == a[i - 1]){
			i++;
			continue;
		}
		cout << a[i] << " ";
		i++;
	}
	while(j < n){
		if(j > 0 && b[j] == b[j - 1]){
			j++;
			continue;
		}
		cout << b[j] << " ";
		j++;
	}
	return 0;
}