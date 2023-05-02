#include<iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);
void heapSort(int arr[], int n);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	heapSort(arr, n);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void buildHeap(int arr[], int n){
	for(int i = (n - 2) / 2; i >= 0; i--){
		maxHeapify(arr, n, i);
	}
}
void maxHeapify(int arr[], int n, int i){
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		maxHeapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n){
	buildHeap(arr, n);
	for(int i = n - 1; i >= 1; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, i, 0);
	}
}