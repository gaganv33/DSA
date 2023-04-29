#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		int min_ind = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[min_ind]){
				min_ind = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_ind];
		arr[min_ind] = temp;
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}