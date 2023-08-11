#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		vector<int> ans;
		ans.push_back(a[0]);
		bool found = false;
		cout << 1;
		
		for(int i = 1; i < n; i++){
			if(ans.back() <= a[i]){
				if(!found){
					ans.push_back(a[i]);
					cout << 1;
				}
				else{
					if(ans.front() >= a[i]){
						ans.push_back(a[i]);
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
			}
			else{
				if(a[i] > ans.front()){
					cout << 0;
				}
				else if(a[i] <= ans.front()){
					if(!found){
						found = true;
						ans.push_back(a[i]);
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}