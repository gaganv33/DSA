#include<bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin >> n;
	stack<char> s;
	
	for(auto x : n){
		if(x == '(' || x == '[' || x == '{'){
			s.push(x);
		}	          
		else{
			if(s.empty()){
				cout << "Not balanced" << endl;
				return 0;
			}
			else{
				bool value = (s.top() == '(' && x == ')') ||
						(s.top() == '[' && x == ']') ||
						(s.top() == '{' && x == '}');
				if(value){
					s.pop();
				}		
				else{
					cout << "Not balanced" << endl;
					return 0;
				}	
			}
		}         	
	}
	if(s.empty()){
		cout << "Balanced" << endl;
	}
	else{
		cout << "Not balanced" << endl;
	}
	return 0;
}