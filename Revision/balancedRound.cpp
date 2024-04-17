#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		if(n == 1){
			cout << 0 << "\n";
		}
		else{
			sort(v.begin(), v.end());
			vector<int> b;
			for(int i = 0; i < n; i++){
				if(i == 0){
					b.push_back(abs(v[i] - v[i + 1]));
				}
				else if(i == n - 1){
					b.push_back(abs(v[i] - v[i - 1]));
				}
				else{
					b.push_back(max(abs(v[i] - v[i - 1]), abs(v[i] - v[i + 1])));
				}
			}
			int max_length = -1;
			int length = 0;
			for(int i = 0; i < b.size(); i++){
				if(b[i] <= k){
					length++;
					max_length = max(max_length, length);
				}
				else{
					length = 0;
				}
			}
			cout << max_length << endl;
		}
	}
	return 0;
}