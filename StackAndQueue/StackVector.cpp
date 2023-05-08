#include<bits/stdc++.h>
using namespace std;

struct Stack{
	vector<int> v;
	void push(int x){
		v.push_back(x);
	}
	int pop(){
		int res = v.back();
		v.pop_back();
		return res;
	}
	int size(){
		return v.size();
	}
	int peek(){
		return v.back();
	}
	bool isEmpty(){
		return v.empty();
	}
	void print(){
		for(int i = 0; i < size(); i++){
			cout << v[i] << " ";
		}	
		cout << endl;
		return;
	}
};
int main(){
	Stack s;
	s.push(5);
	s.push(15);
	s.push(25);
	s.print();
	cout << s.size() << endl;
	cout << s.peek() << endl;
	cout << s.pop() << endl;
	s.push(35);
	s.print();
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
	return 0;	
}