#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h);

int main(){
	int r, c;
	cin >> r >> c;
	vector<vector<int>> v;
	for(int i = 0; i < r; i++){
		vector<int> a;
		for(int j = 0; j < c; j++){
			int value;
			cin >> value;
			a.push_back(value);
		}
		v.push_back(a);
	}
	int arr[r * c]; 
	int index = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			arr[index] = v[i][j];
			index = index + 1;
		}
	}
	int l = 0;
	int h = (r * c) - 1;
	int k = (r * c) / 2;

	while(l <= h){
		int p = partition(arr, l, h);
		if(p == k - 1){
			cout << arr[p + 1] << endl;
			break;
		}
		else if(p < k - 1){
			l = p + 1;
		}
		else if(p > k - 1){
			h = p - 1;
		}
	}
	for(int i = 0; i < (r * c); i++){
		cout << arr[i] << " ";
	}
	return 0;
}

int partition(int arr[], int l, int h){
	int i = l - 1;
	// Pivot is the last element
	int pivot = arr[h];
	for(int j = l; j <= h - 1; j++){
		if(arr[j] < pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;	
		} 
	}
	i = i + 1;
	int temp = arr[i];
	arr[i] = arr[h];
	arr[h] = temp;
	return i;
}