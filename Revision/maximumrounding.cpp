#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long int n;
		cin >> n;
		vector<int> v;
		while(n > 0){
			v.push_back(n % 10);
			n = n / 10;
		}
		unsigned long long int ans = 0;
		int i = 1;
		while(i < v.size()){
			unsigned long long int value = 0;
			if(v[i - 1] >= 5){
				if(v[i] != 9){
					v[i]++;
					i++;
				}
				else{
					int min_val = INT_MAX;
					int index = -1;
					for(int j = i + 1; j < v.size(); j++){
						if(v[j] < min_val){
							min_val = v[j];
							index = j;
						}
					}
					if(index == -1){
						for(int k = 0; k < v.size(); k++){
							v[k] = 0;
						}
						v.push_back(1);
						break;
					}
					else{
						v[index]++;
						i = index;
					}
				}
			}
			for(int j = 0; j < i; j++){
				v[j] = 0;
			}
			for(int k = 0; k < v.size(); k++){
				value += (pow(10, k) * v[k]);
			}
			ans = max(ans, value);
		}
		unsigned long long int value = 0;
		for(int k = 0; k < v.size(); k++){
			value += (pow(10, k) * v[k]);
		}
		ans = max(ans, value);
		cout << ans << "\n";
	}
	return 0;
}