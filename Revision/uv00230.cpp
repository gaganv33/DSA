#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string> v;
	while(1){
		string input;
		getline(cin, input);
		if(input == "END"){
			break;
		}
		v.push_back(input);
	}
	map<string, set<string>> m;
	for(auto x : v){
		string title;
		bool found = 0;
		int i;
		for(i = 0; i < x.length(); i++){
			if(x[i] == '"' && found == 0){
				found = 1;
				continue;
			}
			else if(x[i] == '"' && found == 1){
				break;
			}
			title += x[i];
		}
		i = i + 5;	
		string author;
		for(int j = i; j < x.length(); j++){
			author += x[j];
		}
		m[author].insert(title);
	}
	while(1){
		string input;
		getline(cin, input);
		if(input == "SHELVE"){
			
		}
	}
	return 0;
}