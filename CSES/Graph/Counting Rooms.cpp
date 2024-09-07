#include <bits/stdc++.h>
using namespace std;

vector<int> x = {1, 0, -1, 0};
vector<int> y = {0, 1, 0, -1};

void solve(int i, int j, int n, int m, vector<vector<char>> &v) {
	v[i][j] = '#';
	
	for(int k = 0; k < 4; k++) {
		int newI = i + x[k];
		int newJ = j + y[k];
		if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && v[newI][newJ] == '.') {
			solve(newI, newJ, n, m, v);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v (n, vector<char> (m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(v[i][j] == '.') {
				solve(i, j, n, m, v);
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}