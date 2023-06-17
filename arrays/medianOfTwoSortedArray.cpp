#include<bits/stdc++.h>
using namespace std;

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	vector<double> a1(n1);
	vector<double> a2(n2);
	for(int i = 0; i < n1; i++){
		cin >> a1[i];
	}
	for(int i = 0; i < n2; i++){
		cin >> a2[i];
	}
	// Method - 1 (Using Merge function)
	vector<double> a;
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2){
		if(a1[i] <= a2[j]){
			a.push_back(a1[i]);
			i++;
		}
		else{
			a.push_back(a2[j]);
			j++;
		}
	}
	while(i < n1){
		a.push_back(a1[i]);
		i++;
	}
	while(j < n2){
		a.push_back(a2[j]);
		j++;
	}
	int val = (n1 + n2) / 2;
	if((n1 + n2) % 2 == 0){
		double sum = a[val] + a[val - 1];
		cout << (sum / (double)2) << endl;
		return 0;
	}
	cout << a[val] << endl;
	                             
	return 0;
}