#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		char c;
		string s;
		cin >> c >> s;

		int count = 0;
		if(c == 'g'){
			cout << 0 << endl;
		}	
		else{
			int total = 0;
			for(int i = 0; i < k; i++){
				if(s[i] == c){
					total++;
				}
			}		
			int i = 0;
			while(total > 0){
	                	int value = 0;
				if(s[i] == c){
					while(s[i] != 'g'){
						if(s[i] == c){
							total--;
						}
						value++;
						i = (i + 1) % k;
					}
				}
				i = (i + 1) % k;
				count = max(count, value);
			}
			cout << count << endl;
		}
	}
	return 0;
}