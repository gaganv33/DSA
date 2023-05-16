#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	set<int> s;
	stack<int> st;
	for(int i = n - 1; i >= 0; i--){
		if(i == n - 1){
			st.push(-1);
		}
		else{
			auto it = s.lower_bound(arr[i]);
			if(it == s.end()){
				st.push(-1);
			}
			else{
				//if((*it) >= arr[i]){
				//	st.push(*it);
				//}
				st.push(*it);
			}
		}
		s.insert(arr[i]);
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
} 