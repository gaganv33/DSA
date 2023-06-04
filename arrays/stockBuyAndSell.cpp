#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int first = v[0];
	stack<int> s;
	s.push(first);
	int second;
	int max_profit = 0;
	for(int i = 1; i < n; i++){
		if(s.top() > v[i]){
			max_profit = max_profit + (s.top() - first);
			while(!s.empty()){
				s.pop();
			}		
			first = v[i];
			s.push(first);	
		}
		else{
			s.push(v[i]);
		}
	}
	if(!s.empty()){
		if(s.top() > first){
			max_profit = max_profit + (s.top() - first);
		}
	}
	cout << max_profit << endl;
	return 0;
}