#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	// Moore Volting Algorithm
	int res = 0;
	int count = 1;
	// First phase : Selecting the possible majority element.
	for(int i = 1; i < n; i++){
		if(v[res] == v[i]){
			count++;
		}
		else{
			count--;
		}
		if(count == 0){
			res = i;
			count = 1;
		}
	}
	
	// Second phase : Check if the selected element is a majority element
	count = 0;
	for(int i = 0; i < n; i++){
		if(v[res] == v[i]){
			count++;
		}		
	}
	if(count <= (n / 2)){
		cout << -1 << endl;
		return 0;
	}
	cout << res << "  "  << count << endl;
	return 0;
}