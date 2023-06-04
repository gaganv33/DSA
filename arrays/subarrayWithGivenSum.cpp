#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];	
	}
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
	return 0;
}