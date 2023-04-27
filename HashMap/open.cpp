#include<iostream>
#include<list>
using namespace std;

struct HaspMap{
	int *arr;
	int cap, size;
	HaspMap(int c){
		cap = c;
		size = 0;
		for(int i = 0; i < cap; i++){
			arr[i] = -1;
		}
	}
	int hash1(int key){
		return (key % cap);
	}
	int hash2(int key){
		int new_cap = cap - 1;
		return new_cap - (key % new_cap);
	}
	int search(int key){
		int h = hash1(key);
		int offset = hash2(key);
		int i = h;
		int index = 1;
		while(arr[i] != -1){
			if(arr[i] == key)
				return 1;
			else{
				i = (h + (index * offset)) % cap;
				index = index + 1;
			}
			if(i == h)
				return 0;
		}
		return 0;
	}
	int insert(int key){
		if(size == cap){
			return 0;		
		}
		int h = hash1(key);
		int offset = hash2(key);
		int i = h;
		int index = 1;
		while(arr[i] != -1 && arr[i] != -2 && arr[i] != key){
			i = (h + (index * offset)) % cap;
			index = index + 1;
		}
		if(arr[i] == key){
			return 0;
		}
		else{
			arr[i] = key;
			size++;
			return 1;
		}
	}
	int erase(int key){
		int h = hash1(key);
		int offset = hash2(key);
		int index = 1;
		int i = h;
		while(arr[i] != -1){
			if(arr[i] == key){
				arr[i] = -2;
				size = size - 1;
				return 1;
			}	
			else{
				i = (h + (index * offset)) % cap;
				index = index + 1;	
			}
			if(i == h)
				return 0;
		}
		return 0;
	}
	int *print(){
		return arr;
	}
};

int main(){
	cout<<"Enter the value of bucket"<<endl;
	int n;
	cin>>n;
	HaspMap hm(n);
	cout<<hm.insert(49)<<endl;	
	cout<<hm.insert(63)<<endl;
	cout<<hm.insert(56)<<endl;
	cout<<hm.insert(52)<<endl;
	cout<<hm.insert(54)<<endl;
	cout<<hm.insert(48)<<endl;
	int *arr = hm.print();
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<"  ";
	}
	return 0;
}