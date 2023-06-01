#include<bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int x = m ^ n;
	if(x == 0){
		cout << 0 << endl;
		return 0;
	}
	int count = 0;
	while(x > 0){
		if(x & 1){
			cout << count + 1 << endl;
			return 0;
		}	
		count++;
		x = (x >> 1);
	}	
	return 0;	        	
}