#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int v[n];
		
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
		
	stack<int> s;
	s.push(0);
	
	for(int i = 0; i < n; i++){
		while(s.empty() == false && v[s.top()] <= v[i]){
			s.pop();
		}
		int res = (s.empty()) ? (i + 1) : (i - s.top());
		cout << res << " ";
		s.push(i);
	}
	return 0;
}