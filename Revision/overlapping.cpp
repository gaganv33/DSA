#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> v;
	int max_width = INT_MIN, min_width = INT_MAX;
	int max_height = INT_MIN, min_height = INT_MAX;
	for(int i = 0; i < n; i++){
		vector<int> b(4);
		cin >> b[0] >> b[1] >> b[2] >> b[3];
		max_width = max(max_width, b[1]);
		min_width = min(min_width, b[0]);
		max_height = max(max_height, b[3]);
		min_height = min(min_height, b[2]);
		v.push_back(b);
	}
	int width = max_width - min_width;
	int height = max_height - min_height;
	vector<vector<bool>> matrix;
	for(int i = 0; i < height; i++){
		vector<bool> col(width, false);
		matrix.push_back(col);
	}
	for(int i = 0; i < n; i++){
		for(int j = v[i][2] ; j < v[i][3]; j++){
			for(int k = v[i][0]; k < v[i][1]; k++){
				if(matrix[j][k] != true){
					matrix[j][k] = true;
				}
			}
		}
	}
	int value = 0;
	for(auto x : matrix){
		for(auto y : x){
			if(y == true){
				value++;
			}
		}
	}
	cout << value << "\n";
	return 0;
}