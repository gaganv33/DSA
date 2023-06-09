#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int maxx = *max_element(v.begin(), v.end());
	if(maxx >= 0){
		vector<int> ct(maxx + 1, 0);
		for(int i = 0; i < n; i++){
			if(v[i] > 0){
				ct[v[i]]++;				
			}
		}		
		for(int i = 1; i < maxx + 1; i++){
			if(ct[i] == 0){
				cout << i << endl;
				return 0;
			}
		}
		cout << maxx + 1 << endl;
		return 0;
	}
	else{
		cout << 1 << endl;
	}
	return 0;
}
