#include<iostream>
using namespace std;

int main(){
	int n, low, mid, high;
	cin >> n;
	int a[n];
	cin >> low >> mid >> high;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int o = mid - low + 1;
	int m = high - mid;
	int left[o];
	int right[m];

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
	while(i < o && j < m){
		if(left[i] <= right[j]){
			a[count] = left[i];
			count++;
			i++;
		}
		else{
			a[count] = right[j];
			count++;
			j++;
		}
	}
	while(i < o){
		a[count] = left[i];
		count++;
		i++;
	}
	while(j < m){
		a[count] = right[j];
		count++;
		j++;
	}
	for(int k = low; k <= high; k++){
		cout << a[k] << " ";
	}        
	return 0;
}