#include<iostream>
using namespace std;

void CountingSort(int arr[], int n);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	CountingSort(arr, n);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
void CountingSort(int arr[], int n){
	int min_val = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] < min_val){
			min_val = arr[i];
		}
	}
	int max_val = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max_val){
			max_val = arr[i];
		}
	}
	
	int size = max_val - min_val + 1;
	int count[size];
	for(int i = 0; i < size; i++){
		count[i] = 0;
	}
	for(int i = 0; i < n; i++){
		count[arr[i] - min_val]++;	
	}
	
	for(int i = 1; i < size; i++){
		count[i] = count[i - 1] + count[i];
	}
	int output[n];
	for(int i = n - 1; i >=0; i--){
		output[count[arr[i] - min_val] - 1] = arr[i];
		count[arr[i] - min_val]--;
	}
	for(int i = 0; i < n; i++){
		arr[i] = output[i];
	}	
}