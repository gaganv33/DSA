#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	// this solution shuffles the initial order
	/*int i = -1;
	int j = n;
	while(true){
		do{
			i++;
		}while(v[i] != 0);
		do{
			j--;
		}while(v[j] == 0);
		if(i >= j){
			break;
		}          
		swap(v[i], v[j]);	
	}*/
	
	// this solution retains the initial order
	int count = 0;
	for(int i = 0; i < n; i++){
		if(v[i] != 0){
			swap(v[i], v[count]);
			count++;
		}
	}
	for(auto x : v){
		cout << x << " ";
	}                        
	return 0;
}