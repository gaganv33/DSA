#include<bits/stdc++.h>
using namespace std;


bool good(int t, int n, int x, int y){
	if(t < min(x, y)){
		return false;
	}
	t = t - min(x, y);
	return (1 + (t / x) + (t / y)) >= n;
}

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	
	int l = 0;
	int r = n * max(x, y);
	
	while(r > (l + 1)){
		int m = l + (r - l) / 2;
		if(good(m, n, x, y)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout << r << endl;
	return 0;
}