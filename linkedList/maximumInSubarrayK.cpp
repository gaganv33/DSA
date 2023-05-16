#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	deque<int> dq;
	for(int i = 0; i < k; i++){
		dq.push_back(arr[i]);
	}
	for(int i = k; i < n; i++){
		int max_value = INT_MIN;
		for(int j = 0; j < k; j++){
			max_value = max(max_value, dq[j]);
		}
		dq.pop_front();
		cout << max_value << " ";
		dq.push_back(arr[i]);
	}
	int max_value = INT_MIN;
	for(int j = 0; j < k; j++){
		max_value = max(max_value, dq[j]);
	}
	cout << max_value << endl;
	return 0;	
}