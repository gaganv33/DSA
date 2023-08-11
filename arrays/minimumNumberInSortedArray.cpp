#include<bits/stdc++.h>
using namespace std;

// Using binary Serach Method
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	if(n == 1){
		cout << v[0] << endl;
		return 0;
	}
	if(v[n - 1] < v[n - 2]){
		cout << v[n - 1] << endl;
		return 0;
	}
	int low = 0;
	int high = n - 1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(v[mid] < v[mid + 1] && v[mid] < v[mid - 1]){
			cout << v[mid] << endl;
			return 0;
		}
		else if(v[mid] > v[high]){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	cout << v[low] << endl;
	return 0;
}