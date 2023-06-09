#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> left(n);
	vector<int> right(n);
	
	for(int i = 0; i < n; i++){
		cin >> left[i] >> right[i];
	}
	
	int maxx = *max_element(right.begin(), right.end()) + 2;
	vector<int> ct(maxx, 0);
	
	for(int i = 0; i < n; i++){
		ct[left[i]] = 1;
		ct[right[i] + 1] = -1;
	}
	
	// Calculating the prefic sum
	for(int i = 1; i < maxx; i++){
		ct[i] = ct[i] + ct[i - 1];
	}
	int res = 0;
	int max_el = ct[0];
	for(int i = 1 ; i < maxx; i++){
		if(ct[i] > max_el){
			max_el = ct[i];
			res = i;
		}
	}               	
	cout << res << endl;
	return 0;
}