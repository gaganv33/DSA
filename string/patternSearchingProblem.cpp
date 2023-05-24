#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	string pat;
	getline(cin, pat);
	int sz = pat.size();
	
	for(int i = 0; i < str.length(); i++){
		string str1 = str.substr(i, sz);
		int res = str1.find(pat);
		if(res != string::npos){
			cout << i << " ";
		}
	}
	
	return 0;
}