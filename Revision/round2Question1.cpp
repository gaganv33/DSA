#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> p1, pair <int, int> p2);

int main(){
	int n;
	cin >> n;
	int arr[n][2];
	for(int i = 0; i < n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	// First column is the id of the student and the second olumn is the marks
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		v.push_back({arr[i][0], arr[i][1]});
	}
	sort(v.begin(), v.end(), myCmp);
	for(int i = 0; i < n; i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;	
}

bool myCmp(pair<int, int> p1, pair <int, int> p2){
	return p1.second > p2.second;
}