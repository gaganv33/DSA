#include<iostream>
using namespace std;

void quickSort(int arr[], int l, int h);
int lomutoPartition(int arr[], int l, int h);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void quickSort(int arr[], int l, int h){
	if(l < h){
		int p = lomutoPartition(arr, l, h);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, h);	
	}
}

int lomutoPartition(int arr[], int l, int h){
	// last element is used as the pivot
	int pivot = arr[h];
	int i = l - 1;
	for(int j = l; j <= h - 1; j++){
		if(arr[j] < pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp2 = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = temp2;
	return (i + 1);
}       