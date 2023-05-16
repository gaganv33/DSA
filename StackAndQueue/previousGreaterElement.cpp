#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	stack<int> s;
	s.push(arr[0]);
	
	for(int i = 0; i < n; i++){
		while(s.empty() == false && s.top() <= arr[i]){
			s.pop();
		}
		int res = (s.empty()) ? -1 : s.top();
		s.push(arr[i]);
		cout << res << " ";
	}
	return 0;
}