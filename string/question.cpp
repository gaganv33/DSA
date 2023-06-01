#include<bits/stdc++.h>
using namespace std;

int main(){
	string pattern, source;
	cin >> pattern;
	cin >> source;
	
	for(int i = 0; i < source.size(); i++){
		if(source[i] == 'a' || source[i] == 'e' || source[i] == 'i' || source[i] == 'o' || source[i] == 'u'){
	        	source[i] = '0';
		}
		else{
			source[i] = '1';
		}
	}
	cout << source << endl;
	int count = 0;
	int n = source.size() - pattern.size();
	for(int i = 0; i <= n; i++){
		if(source.substr(i, pattern.size()) == pattern){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}