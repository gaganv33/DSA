#include <bits/stdc++.h>
using namespace std;
 
vector<int> x = {1, 0, -1, 0};
vector<int> y = {0, 1, 0, -1};
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> v (n, vector<char> (m));
	int startI = -1, startJ = -1;
	int endI = -1, endJ = -1;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> v[i][j];
			if(v[i][j] == 'A') {
				startI = i;
				startJ = j;
			}
			else if(v[i][j] == 'B') {
				endI = i;
				endJ = j;
			}
		}
	}
	
	if((endI == -1 && endJ == -1) || (startI == -1 && startJ == -1)) {
		cout << "NO" << endl;
		return 0;
	}
	
	queue<pair<string, pair<int, int>>> q;
	q.push({"", {startI, startJ}});
	
	while(!q.empty()) {
		pair<string, pair<int, int>> p = q.front();
		q.pop();
		
		string s = p.first;
		int i = p.second.first;
		int j = p.second.second;
		
		if(i == endI && j == endJ) {
			cout << "YES\n";
			cout << (int) s.size() << "\n";
			cout << s << "\n";
			return 0;
		}
 
		v[i][j] = '#';
		
		for(int k = 0; k < 4; k++) {
			int newI = i + x[k];
			int newJ = j + y[k];
			if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && (v[newI][newJ] == '.' || v[newI][newJ] == 'B')) {
				string t = s;
				if(x[k] == 1 && y[k] == 0) {
					t += 'D';
				}
				else if(x[k] == -1 && y[k] == 0) {
					t += 'U';
				}
				else if(x[k] == 0 && y[k] == 1) {
					t += 'R';
				}
				else {
					t += 'L';
				}
				q.push({t, {newI, newJ}});
			}
		}
	}
	
	cout << "NO\n";
	return 0;
}