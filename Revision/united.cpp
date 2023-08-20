#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b, c;
		int max = INT_MIN;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(max < a[i]){
				max = a[i];
			}
		}		
		for(int i = 0; i < n; i++){
			if(a[i] == max){
				c.push_back(a[i]);
			}
			else{
				b.push_back(a[i]);
			}
		}
		if(b.size() == 0 || c.size() == 0){
			cout << -1 << "\n";
		}
		else{
			cout << b.size() << " " << c.size() << "\n";
			for(auto x : b){
				cout << x << " ";
			}
			cout << "\n";
			for(auto x : c){
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}