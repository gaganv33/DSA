#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, pivot;
	cin >> n >> pivot;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int low = 0;
	int mid = 0;
	int high = n - 1;
	while(mid <= high){
		if(arr[mid] < pivot){
			int temp = arr[low];
			arr[low] = arr[mid];
			arr[mid] = temp;
			mid++;
			low++;
		}
		else if(arr[mid] == pivot){
			mid++;
		}
		else{
			int temp = arr[mid];
			arr[mid] = arr[high];
			arr[high] = temp;
			high--;
		}
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}