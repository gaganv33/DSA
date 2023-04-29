#include<iostream>
using namespace std;

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int l, int r);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void mergeSort(int a[], int l, int r){
	if(r > l){
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void merge(int a[], int low, int mid, int high){
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int left[n1];
	int right[n2];
	
	int count = 0;
	for(int i = low; i <= mid; i++){
		left[count] = a[i];
		count++;
	}
	
	count = 0;
	for(int i = mid + 1; i <= high; i++){
		right[count] = a[i];
		count++;
	}
		
	count = low;
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			a[count] = left[i];
			i++;
			count++;
		}
		else{
			a[count] = right[j];
			j++;
			count++;
		}
	}
	while(i < n1){
		a[count] = left[i];
		i++;
		count++;
	}
	while(j < n2){
		a[count] = right[j];
		j++;
		count++;
	}
	return;
}