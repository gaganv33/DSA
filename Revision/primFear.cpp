#include<bits/stdc++.h>
using namespace std;

bool check(int n);
int count_bit(int n);

int main(){
	int n = 1e6;
	vector<bool> a(n + 1, true);
	vector<int> b;
	
	a[0] = a[1] = 0;
	for(int i = 2; i * i <= n; i++){
		if(a[i]){
			for(int j = i * i; j <= n; j+=i){
				a[j] = 0;
			}
		}
	}	
		
	int t;
	cin >> t;
	while(t--){
		int m;
		cin >> m;
		int count = 0;
		for(int i = 2; i <= m; i++){
			bool isPrime = true;
			if(a[i] && check(a[i])){
				int val = i;
				while(val > 0){
					if(a[val] == 0){
						isPrime = false;
						break;					
					}
					int ct = count_bit(val);
					val = val - (pow(10, ct - 1) * (val / (int)pow(10, ct - 1)));
				}
			}
			if(a[i] && isPrime){
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

bool check(int n){
	while(n > 0){
		if(n % 10 == 0){
			return false;
		}
		n = n / 10;
	}
	return true;
}
int count_bit(int n){
	int count = 0;
	while(n > 0){
		count++;
		n = n / 10;
	}
	return count;
}
