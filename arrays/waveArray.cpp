#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}                   	
	// Sorting the array in case it is not sorted
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n - 1; i = i + 2){
		int temp = v[i];
 		v[i] = v[i + 1];
		v[i + 1] = temp;
	}
	for(auto x : v){
		cout << x << " ";
	}
	return 0;
}