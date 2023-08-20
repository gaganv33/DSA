#include<bits/stdc++.h>
using namespace std;
	
bool goodBad(long long i, int w, int h, int n){
	return ((i / w) * (i / h)) >= n;		
}

int main(){
	int w, h, n;
	cin >> w >> h >> n;
	
	long long l = 0;
	long long r = 1;
	
	int i = 0;
	
	while(!goodBad(r << i, w, h, n)){
		i++;
	}
	r = r << i;
	
	while(r > (l + 1)){
		long long m = (r + l) / 2;
		if(goodBad(m, w, h, n)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout << r << endl;	
	return 0;
}