#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int solve(int index, string &s, vector<int> &dp) {
	if(index >= s.size()) {
		return s[index] == '@';
	}
	
	if(s[index] == '*') {
		return 0;
	}
	
	if(dp[index] != -1) {
		return dp[index];
	}
	
	int answer = 0;
	
	if(s[index] == '@') {
		answer = max(answer, 1 + solve(index + 1, s, dp));
		answer = max(answer, 1 + solve(index + 2, s, dp));
	}
	
	else {
		answer = max(answer, solve(index + 1, s, dp));
		answer = max(answer, solve(index + 2, s, dp));
	}
	
	return dp[index] = answer;
}

int main() {
	int t;
	cin >> t;
	
	
	for(int z = 0; z < t; z++) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		
		vector<int> dp (n, -1);
		
		cout << solve(0, s, dp) << endl;
		
	}
	return 0;
} 