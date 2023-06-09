#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	 Given a sorted array of positive integers. Your task is to rearrage the array elements alternatively
	 i.e., first element should be max value, second value should be minimum value, third value should be second max value,
	 fourth value should be second minimum value and so on..		
	*/
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int maxx = *max_element(v.begin(), v.end()) + 1;	

	int l = 0;
	int h = n - 1;
	int i = 0;
	
	while(i < n){
		if(i % 2 == 0){
			v[i] += ((v[h] % maxx) * maxx);
			h--;
		}	
		else{
			v[i] += ((v[l] % maxx) * maxx);
			l++;	
		}	
		i++;
	}
	for(int i = 0; i < n; i++){
		v[i] /= maxx;
	}
	for(auto x : v){
		cout << x << " ";
	}
	return 0;
}