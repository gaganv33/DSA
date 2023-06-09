#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	// Condition for ascending order
	int count = 0;
	if(v[0] >= v[n - 1]){
		for(int i = 0; i < n - 1; i++){
			if(v[i] > v[i + 1]){
				count++;
			}			
		}
	}
	else{
		for(int i = 0; i < n - 1; i++){
			if(v[i] < v[i + 1]){
				count++;
			}
		}
	}
	if(count == 1){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;	
}