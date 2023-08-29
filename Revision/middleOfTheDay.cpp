#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	int middle = (sum + 1) / 2;
	int index = 0;
	for(int i = 0; i < n; i++){
		if(middle < a[i]){
			break;
		}
		index = i + 1;
		middle -= a[i];
	}
	if(middle == 0){
		cout << index << " " << a[index - 1] << "\n";
	}
	else{
		cout << index + 1 << " " << middle << "\n";
	}
	return 0;
}
