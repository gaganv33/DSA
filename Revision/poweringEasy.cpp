#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<long long, long long> m;
		priority_queue <long long> q;
		long long count = 0;
		for(int i = 0; i < n; i++){
			long long input;
			cin >> input;
			if(input != 0){
				m[input]++;
				q.push(input);
			}
			else{
				if(!q.empty()){
					long long value = q.top();
					q.pop();
					pair<long long, long long> p = *m.find(value);
					if(p.second == 1){
						m.erase(value);
					}
					else{
						m[value]--;
						q.push(value);
					}
					count += value;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}