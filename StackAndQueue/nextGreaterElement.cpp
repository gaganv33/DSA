#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	
	for(int  i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	stack<int> s;
	vector<int> ans;
	s.push(arr[ n - 1]);
	for(int i = n - 1; i >= 0; i--){
		while(s.empty() == false && s.top() <= arr[i]){
			s.pop();
		}
		int res = (s.empty()) ? -1 : s.top();
		s.push(arr[i]);
		ans.push_back(res);
	}
	for(auto it = ans.rbegin(); it != ans.rend(); it++){
		cout << (*it) << " ";
	}
	return 0;
}