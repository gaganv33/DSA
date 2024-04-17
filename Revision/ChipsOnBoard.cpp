#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	for(int a = 0; a < t; a++) {
		int n;
		cin >> n;
		vector<int> v, w;
		int row_min = INT_MAX;
		int col_min = INT_MAX;
		
		for(int i = 0; i < n; i++) {
			int value;
			cin >> value;
			v.push_back(value);
			row_min = min(row_min, value);
		}
		
		for(int i = 0; i < n; i++) {
			int value;
			cin >> value;
			w.push_back(value);
			col_min = min(col_min, value);
		}
		
		long long total_row = 0;
		long long total_col = 0;
		
		for(int i = 0; i < n; i++) {
			total_row += (col_min + v[i]);
			total_col += (row_min + w[i]);
		}
	
		cout << min(total_row, total_col) << endl;
	}
	
	return 0;
}