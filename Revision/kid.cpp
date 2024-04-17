#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int min_value = INT_MAX;
	for(int i = 0; i < n; i++){
		int value;
		cin >> value;
		min_value = min(min_value, abs(value));
	}
	cout << min_value << endl;
	return 0;
}