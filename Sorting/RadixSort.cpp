#include<iostream>
using namespace std;

void RadixSort(int arr[], int n);
void CountingSort(int arr[], int n, int exp);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	RadixSort(arr, n);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void RadixSort(int arr[], int n){
	int max_val = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max_val){
			max_val = arr[i];
		}
	}
	for(int exp = 1; (max_val / exp) > 0; exp = exp * 10){
		CountingSort(arr, n, exp);
	}
}

void CountingSort(int arr[], int n, int exp){
	int count[10];
	int output[n];
	for(int i = 0; i < 10; i++){
		count[i] = 0;
	}
	for(int i = 0; i < n; i++){
		count[(arr[i] / exp) % 10]++;
	}
	for(int i = 1 ; i < 10; i++){
		count[i] = count[i - 1] + count[i];
	}
	// Iterating from n - 1 to 0, since it is stable soring algorithm.
	for(int i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for(int i = 0; i < n; i++){
		arr[i] = output[i];
	}
}