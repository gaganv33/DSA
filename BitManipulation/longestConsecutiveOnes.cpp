#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int c = 0;
	int ans = 0;
	while(n > 0){
		if(n & 1){
			c++;
		}		
		else{
			ans = max(ans, c);
			c = 0;
		}
		n = (n >> 1);
	}
	ans = max(ans, c);
	cout << ans << endl;
	return 0;
}