#include<iostream>
using namespace std;

int main(){
	int n, p;
	cin >> n >> p;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int temp[n];
	int index = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] <= arr[p]){
			temp[index] = arr[i];
			index++;
		}
	}
	for(int i = 0; i < n; i++){
		if(arr[i] > arr[p]){
			temp[index] = arr[i];
			index++;
		}
	}
	
	for(int i = 0; i < n; i++){
		arr[i] = temp[i];
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
