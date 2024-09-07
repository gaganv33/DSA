#include <bits/stdc++.h>
using namespace std;

int solve(int index, int k, string &s, string &t, vector<vector<int>> &dp) {
	if(k == 0 || index >= (int) s.size()) {
		int ans = 0;
		for(int i = 0; i < (int) s.size(); i++) {
			int j = i;
			int k = 0;
			bool found = true;
			
			while(j < (int) s.size() && k < (int) t.size()) {
				if(s[j] != t[k]) {
					found = false;
				}
				j++;
				k++;
			}
			if(k == (int) t.size() && found) ans++;
		}
		
		return ans;
	}
	
	if(dp[index][k] != -1) return dp[index][k];
	
	int skip = solve(index + 1, k, s, t, dp);
	int notSkip = 0;
	
	int cnt = 0;
	int i = 0;
	int j = 0;
	while(i < (int) s.size() && j < (int) t.size()) {
		if(s[i] != t[j]) {
			s[i] = t[j];
			cnt++;
		}
		i++;
		j++;
	}
	if(j == (int) t.size() && cnt <= k) {
		notSkip = solve(index + (int) t.size(), k - cnt, s, t, dp);
	}
	
	return dp[index][k] = max(skip, notSkip);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	
	vector<vector<int>> dp (n, vector<int> (k + 1, -1));
	
	cout << solve(0, k, s, t, dp) << endl;

	return 0;
}
