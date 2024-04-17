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
	int n;
	string s;
	cin >> n >> s;
	
	string t = "";
	int i = 0;
	
	while(i < n) {
		t += s[i];
		i++;
		t += s[i];
		i++;
		if(i == n - 1) {
			t += s[i];
			break;
		}
		if(i < n && (s[i] == 'a' || s[i] == 'e')) {
			t += '.';
		}
		else if(i < n) {
			if(i + 1 < n && (s[i + 1] != 'a' && s[i + 1] != 'e')) {
				t += s[i];
				i++;
			}
			t += '.';
		}
	}
	
	cout << t << endl;
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