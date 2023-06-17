#include<bits/stdc++.h>
using namespace std;

// You are given (N + 2) integer elements. All elements of the arrays are in the range from 1 to N. 
// Also the elements occur once except two numbers which occur twice. Find the two repeating elements.

int main(){
	int n;
	cin >> n;
	vector<int> v(n + 2);
	for(int i = 0; i < (n + 2); i++){
		cin >> v[i];
	}
	// Using the array elements as the index and solving.	
	vector<int> a = {0, 0};
	int j = 0;
	for(int i = 0; i < (n + 2); i++){
		int val = abs(v[i]);
		if(v[val] < 0){
			a[j] = val;
			j++;
		}
		else{
			v[val] *= -1;
		}
	}
	for(auto x : a){
		cout << x << " ";
	}
	return 0;
}