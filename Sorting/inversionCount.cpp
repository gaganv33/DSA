#include <bits/stdc++.h>
using namespace std;

int InversionCount(int arr[], int l, int r);
int InverseMerge(int arr[], int l, int m, int r);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i< n; i++){
		cin >> arr[i];
	}
	int ans = InversionCount(arr, 0, n - 1);
	cout << ans << endl;
	return 0;
}

int InversionCount(int arr[], int l, int r){
	int res = 0;
	if(r > l){
		int m = l + (r - l) / 2;
		res += InversionCount(arr, l, m);
		res += InversionCount(arr, m + 1, r);
		res += InverseMerge(arr, l, m, r);
	}
	return res;
}

int InverseMerge(int arr[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int left[n1];
	int right[n2];
	
	int res = 0;
	
	int index = 0;	
	for(int i = l; i <= m; i++){
		left[index] = arr[i];
		index++;
	}
	
	index = 0;
	for(int i = m + 1; i <= r; i++){
		right[index] = arr[i];
		index++;
	}
	
	index = l;
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2){
		if(left[i] < right[j]){
			arr[index] = left[i];
			index++;
			i++;
		}
		else{
	        	arr[index] = right[j];
			index++;
			j++;
			res = res + (n1 - i);
		}
	}
	while(i < n1){
		arr[index] =  left[i];
		index++;
		i++;
	}
	while(j < n2){
		arr[index] = right[j];
		index++;
		j++;
	}
	return res;
} 