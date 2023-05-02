#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if(n == 1 || n == 0){
		cout << INT_MAX << endl;
		return 0;
	}
	sort(arr, arr + n);
	int diff = arr[1] - arr[0];
	for(int i = 1; i < n - 1; i++){
		diff = min(diff, arr[i + 1] - arr[i]);
	}
	cout << diff << endl;
	return 0;
}