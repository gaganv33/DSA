#include<iostream>
using namespace std;

int partition(int arr[], int l, int h);
void qSort(int arr[], int l, int h);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	qSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;	
}

void qSort(int arr[], int l, int h){
	if(l < h){
		int p = partition(arr, l, h);
		qSort(arr, l, p);
		qSort(arr, p + 1, h);
	}
}

int partition(int arr[], int l, int h){
	int pivot = arr[l];
	int i = l - 1;
	int j = h + 1;
	while(true){
		do{
			i++;
		}while(arr[i] < pivot);
		
		do{
			j--;
		}while(arr[j] > pivot);
		if(i >= j){
			return j;
		}
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}