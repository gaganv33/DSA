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

void input(int n, vector<int> &a) {
	for(int i = 0; i < n; i++) cin >> a[i];
}

bool compareDescending(pair<int, int> &a, pair<int, int> &b) {
	if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}
 
void gagan() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	input(n, a);
	input(n, b);
	
	// {pages, threshold}
	vector<pair<int, int>> v;
	
	for(int i = 0; i < n; i++) {
		v.push_back({a[i], b[i]});
	}
	sort(v.begin(), v.end(), compareDescending);
	
	for(auto x : v) {
		cout << x.first << " " << x.second << endl;
	}
	
	int ans = 0;
	int count = 0;
	int index = 0;
	vector<int> visited;
	
	while(index < n) {
		pair<int, int> p = v[index];
		if(p.second > count) {
			count++;
			ans += p.first;
			visited.push_back(p.second);
			index++;
		} else {
			while(index < n && v[index].second <= count) {
				index++;
			}
			vector<int> b;
			for(int i = 0; i < (int) visited.size(); i++) {
				if(visited[i] > count) b.push_back(visited[i]);
				else count--;
			}
			visited = b;
		}
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