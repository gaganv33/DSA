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

long long res(int n) {
	long long sum = 0;
	while(n > 0) {
		sum += (n % 10);
		n = n / 10;
	}
	
	return sum;
}

void solve(vector<long long> &v){
	int n;
	cin >> n;

	cout << v[n - 1] << endl;
}


signed main(){
    fast;
    int t = 1;
    cin >> t;
    
    vector<long long> v;
    long long ans = 0;
    for(int i = 1; i <= 200000; i++) {
    	ans = ans + res(i);
    	v.push_back(ans);
    }
    
    
    while(t--){
    	solve(v);
    }
    return 0;
}