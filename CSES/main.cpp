#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int total = (n * (n + 1)) / 2;
	int sum = 0;
	for(int i = 0; i < n - 1; i++) {
		int val; cin >> val;
		sum += val;
	}
	cout << (total - sum) << endl;
	return 0;
}
