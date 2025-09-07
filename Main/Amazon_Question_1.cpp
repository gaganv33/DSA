#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

vector<int> xCor = {1, 0, -1, 0};
vector<int> yCor = {0, 1, 0, -1};

void print(vector<int> &arr) {
	for(auto x: arr) {
		cout << x << " ";
	}
	cout << endl;
}

int find_set(int node, vector<int> &parent) {
	if(parent[node] == -1) {
		return node;
	}
	return parent[node] = find_set(parent[node], parent);
}

pair<int, int> find_set(pair<int, int> node, map<pair<int, int>, pair<int, int>> &parent) {
	pair<int, int> p = parent[node];
	if(p.first == -1 && p.second == -1) {
		return node;
	}
	return parent[node] = find_set(parent[node], parent);
}

void union_set(int x, int y, vector<int> &parent, vector<int> &rank) {
	int s1 = find_set(x, parent);
	int s2 = find_set(y, parent);
	
	if(s1 != s2) {
		if(rank[s1] < rank[s2]) {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		} else {
			parent[s2] = s1;
			rank[s1] += rank[s2];			
		}
	}
}

void union_set(pair<int, int> x, pair<int, int> y, map<pair<int, int>, pair<int, int>> &parent, 
	map<pair<int, int>, int> &rank) {
	pair<int, int> s1 = find_set(x, parent);
	pair<int, int> s2 = find_set(y, parent);
	
	if((s1.first != s2.first) || (s1.second != s2.second)) {
		if(rank[s1] < rank[s2]) {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		} else {
			parent[s2] = s1;
			rank[s1] += rank[s2];			
		}
	}
}

bool compare(const pair<int, ll> &x, const pair<int, ll> &y) {
	if(x.first == y.first) return (x.second > y.second);
	return x.first < y.first;
}

void dfs(int node, vector<vector<int>> &v, vector<bool> &visit) {
	visit[node] = true;

	for(auto x : v[node]) {
		if(!visit[x]) {
			dfs(x, v, visit);
		}
	}
}

void output(map<char, int> m) {
	cout << "[printing]" << endl;
	for(auto x : m) {
		cout << x.first << " " << x.second << endl;
	}
}

bool check(map<char, int> a, map<char, int> b, int target) {
	int count = 0;
	for(auto x : a) {
		if(b.find(x.first) != b.end()) {
			count++;
		}
	}
	return count > target;
}
 
void gagan() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	vector<map<char, int>> pre (n, map<char, int> ());
	vector<map<char, int>> suf (n, map<char, int> ());
	
	pre[0][s[0]]++;
	for(int i = 1; i < n; i++) {
		map<char, int> temp = pre[i - 1];
		temp[s[i]]++;
		pre[i] = temp;
	}
	
	suf[n - 1][s[n - 1]]++;
	for(int i = n - 2; i >= 0; i--) {
		map<char, int> temp = suf[i + 1];
		temp[s[i]]++;
		suf[i] = temp;
	}
	int ans = 0;
	for(int i = 0; i < n - 2; i++) {
		if(check(pre[i], suf[i + 1], k)) ans++;
	}
	cout << ans << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		gagan();
	}
	
	return 0;
}