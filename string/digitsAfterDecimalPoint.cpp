#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int res = str.find('.');
	if(res != string::npos){
		for(int i = res + 1; i < str.length(); i++){
			cout << str[i];
		}
	}
	return 0;
}
