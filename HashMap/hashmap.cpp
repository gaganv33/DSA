#include<iostream>
#include <list>
using namespace std;

struct HaspMap{
	int bucket;
	list<int> *table;
	HaspMap(int b){
		bucket = b;
		table = new list<int>[b];
	}
	void insert(int key){
		int i = key % bucket;
		table[i].push_back(key);
	}
	int search(int key){
		int i = key % bucket;
		for(auto x: table[i]){
			if(x == key){
				return 1;
			}
		}
		return 0;
	}
	void remove(int key){
		int i = key % bucket;
		table[i].remove(key);
	}

};

int main(){
	cout<<"Enter the size of the bucket"<<endl;
	int b;
	cin>>b;
	HaspMap h1(b);
	h1.insert(2);
	cout<<h1.search(2)<<endl;
	cout<<h1.search(3)<<endl;
	h1.remove(2);
	return 0;
}       