#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	int s, e;
	cin >> s >> e;
	unordered_map<int, unordered_set<int>> v;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	int ans = INT_MAX;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	
	q.push({0, s});
	unordered_set<int> st;
	st.insert(s);

	while(!q.empty()) {
		pair<int, int> p = q.top();
		q.pop();

		int val = p.first;
		int node = p.second;

		if(node == e) {
			cout << val << endl;
			return 0;
		}
		if(node != s && st.find(node) != st.end()) continue;
		st.insert(node);

		for(auto x : v[node]) {
			q.push({max(val, abs(a[node - 1] - a[x - 1])), x});
		}
	}
	cout << ans << endl;
	return 0;
	
}