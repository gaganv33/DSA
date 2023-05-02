#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int low = 0;
	int mid = 0;
	int high = n - 1;	
	while(mid <= high){
		if(arr[mid] == 0){
			int temp = arr[mid];
			arr[mid] = arr[low];
			arr[low] = temp;
			low++;
			mid++;
		}
		else if(mid == 1){
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