#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


void solve(){
	vector<string> v;
	for(int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	int col = -1;
	bool found = false;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(v[i][j] == '?') {
				found = true;
				col = j;
				break;
			}
		}
		if(found) {
			break;
		}
	}
	
	unordered_set<char> m;
	for(int i = 0; i < 3; i++) {
		if(v[i][col] != '?') {
			m.insert(v[i][col]);
		}
	}
	
	for(char i = 'A'; i <= 'C'; i++) {
		if(m.find(i) == m.end()) {
			cout << i << endl;
			return;
		}
	}
}


signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}