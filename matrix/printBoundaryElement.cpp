#include<bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int arr[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	for(int j = 0; j < n; j++){
		cout << arr[0][j] << " ";
	}
	for(int i = 1; i < m; i++){
		cout << arr[i][n - 1] << " ";
	}
	if(m > 1){
		for(int j = n - 2; j >= 0; j--){
			cout << arr[m - 1][j] << " ";
		}
	}
	if(n > 1){
		for(int i = m - 2; i >= 1; i--){
			cout << arr[i][0] << " ";
		}
	}
	return 0;
}