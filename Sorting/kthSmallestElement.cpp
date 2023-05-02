#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r);
int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int l = 0;
	int r = n-  1;
	while(l <= r){
		int p = partition(arr, l, r);
		if(p == k - 1){
			cout << arr[p] << endl;	
			return 0;
		}
		else if(p > k - 1){
			r = p - 1;
		}
		else{
			l = p + 1;
		}
	}	
	cout << -1 << endl;	
	return 0;
}

int partition(int arr[], int l, int r){
	// lomuto Partition
	int pivot = arr[r];
	int i = l - 1;
	for(int j = l; j <= r - 1; j++){
		if(arr[j] < pivot){
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp2 = arr[r];
	arr[r] = arr[i + 1];
	arr[i + 1] = temp2;
	return (i + 1);
}