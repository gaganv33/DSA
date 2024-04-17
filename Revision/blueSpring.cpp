#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	long long p;
	cin >> n >> d;
	cin >> p;
	vector<long long> f(n);
	for(int i = 0; i < n; i++){
		cin >> f[i];
	}
	sort(f.begin(), f.end(), greater<long long> ());
	long long cost = 0;
	long long sum = 0;
	int i = 0;
	while(i < n){
		int m = i + d;
		int j = i;
		sum = 0;
		while(j < m && j < n){
			sum += f[j];
			j++;
		}
		i = i + d;
		if(sum > p){
			cost += p;
		}
		else{
			cost += sum;
		}
	}
	cout << cost << "\n";
	return 0;
}