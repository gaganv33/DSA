#include<bits/stdc++.h>
using namespace std;

bool myCmp(int x, int y){
	return x > y;
}

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n, myCmp);
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += arr[i];
	}
	cout << sum << endl;
	return 0;
}