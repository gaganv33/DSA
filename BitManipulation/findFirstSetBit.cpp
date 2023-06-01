#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	int count = 0;
	while(n > 0){
		if(n & 1){
			cout << (count + 1) << endl;
			return 0;
		}
		count++;
		n = (n >> 1);		
	}                    	
	return 0;
}