#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n], temp[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		temp[i] = arr[i];
	}

	// Solving using Hoare's Partition
	int i = -1;
	int j = n;
	while(true){
		do{
			i++;
		}while(arr[i] % 2 == 0);
		do{
			j--;		
		}while(arr[j] % 2 != 0);
		if(i >= j){
			break;
		}
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	cout << "Using Hoare's Partition method" << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}	

	// Solving using Lomuto Partition method
	for(int i = 0; i < n; i++){
		arr[i] = temp[i];
	}
	
	cout << endl;
	i = -1;
	for(int j = 0; j < n; j++){
		if(arr[j] % 2 == 0){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	cout << "Using lomuto Partition method" << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}