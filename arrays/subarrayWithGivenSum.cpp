#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];	
	}
	/*
	int s = 0;
	int curr = 0;
	for(int i = 0; i < n; i++){
		curr = curr + v[i];
		while(curr > k){
			curr -= v[s];
			s++;
		}
		if(curr == k){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	*/
	
	// Note - 1 is the base indexing
	// Return the left and right index of the subarray
	vector<int> a;
	int sum = 0;
	int start = 0;
	bool found = false;
	
	for(int end = 0; end < n; end++){
		sum += v[end];
		while(sum > k && start != n && start <= end){
			sum -= v[start];
			start++;			
		}
		if(sum == k && start <= end){
			found = true;
			a.push_back(start + 1);
			a.push_back(end + 1);
			break;
		}
	}	
	if(!found){
		a.push_back(-1);
	}
	for(auto x : a){
		cout << x << " ";
	}
	return 0;
}