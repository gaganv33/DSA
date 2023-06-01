#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int count = 1;
	int diff = v[0];
	for(int i = 1; i < n; i++){
		if(diff != v[i]){
			cout << diff << " " << count << endl;
			diff = v[i];
			count = 1;
		}		
		else{
			count++;
		}
	}
	cout << diff << " " << count << endl;
	return 0;
}