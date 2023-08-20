#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		int evenCount = 0;
		long long sum = 0;
		for(int i = 0; i < n; i++){
			int val;
			cin >> val;
			if(val % 2 == 0){
				evenCount++;
			}
			sum += val;
		}
		while(q--){
			int index;
			long long number;
			cin >> index >> number;
			if(index == 0 && number % 2 == 0){
				sum += (evenCount * number);
			}
			else if(index == 0 && number % 2 == 1){
				sum += (evenCount * number);
				evenCount = 0;
			}
			else if(index == 1 && number % 2 == 0){
				sum += ((n - evenCount) * number);
			}
			else if(index == 1 && number % 2 == 1){
				sum += ((n - evenCount) * number);
				evenCount = n;
			}
			cout << sum << "\n";
		}
	}
	return 0;
}