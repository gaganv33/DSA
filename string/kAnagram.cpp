#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	cin >> k;
	string str1, str2;
	cout << "String 1" << endl;
	cin >> str1;
	cout << "String 2" << endl;
	cin >> str2;
	
	if(str1.size() != str2.size()){
		cout << "No" << endl;
		return 0;
	}	
	int count[26] = {0};
	for(int i = 0; i < str1.size(); i++){
		char x = str1[i];
		if(x >= 'a' && x <= 'z'){
			count[x - 'a']++;
		}
		if(x >= 'A' && x <= 'Z'){
			count[x - 'A']++;
		}
	}
	for(int i = 0; i < str2.size(); i++){
		char x = str2[i];
		if(x >= 'a' && x <= 'z'){
			if(count[x - 'a'] != 0){
				count[x - 'a']--;
			}
		}
		if(x >= 'A' && x <= 'Z'){
			if(count[x - 'A'] != 0){
				count[x - 'A']--;
			}
		}
	} 
	int sum = 0;
	sum = accumulate(count, count + 26, sum);
	if(sum > k){
		cout << "No" << endl;
		return 0;
	}	
	cout << "Yes" << endl;
	return 0;
}