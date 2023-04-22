#include<iostream>
using namespace std;

struct HashMap{
	int arr[50][2];
	int cap, size;
	HashMap(int c){
		cap = c;
		size = 0;
		for(int i = 0; i < cap; i++){
			arr[i][0] = arr[i][1] = -1;
		}
	}
	int hash(int key){
		return (key % cap);
	}	
	int new_hash(int key){
		int new_cap = cap - 1;
		return (new_cap - (key % new_cap));
	}
	int search(int key){
		// Returns the index position of the key
		int h = hash(key);
		int offset = new_hash(key);
		int index = 1;
		int i = h;
		
		while(arr[i][0] != -1){
			if(arr[i][0] == key){
				return i;
			}
			else{
				i = (i + (index * offset)) % cap;
				index = index + 1;
			}
			if(i == h){
				// Element not found
				return -1;
			}
		}
		return -1;
	}
	int insert(int key){
		if(size == cap){
			return -1;
		}
		int h = hash(key);
		int offset = new_hash(key);
		int index = 1;
		int i = h;
		while(arr[i][0] != -1 && arr[i][0] != key){
			i = (i + (index * offset)) % cap;	
			index = index + 1;		
		}
		if(arr[i][0] == key){
			// If the key is matching then update the value in the hash table
			return update(key);
		}
		else{
			arr[i][0] = key;
			arr[i][1] = 1;
			size = size + 1;
			return 1;
		}
	}
	int update(int key){
		int h = hash(key);
		int offset = new_hash(key);
		int index = 1;
		int i = h;
		
		int pos = search(key);
		if(pos == -1){
			return -2;
		}
		else{
			arr[pos][1] = arr[pos][1] +  1;
			return 2;
		}
	}
	int count(){
		int total = 0;
		for(int i = 0; i < cap; i++){
			if(arr[i][0] != -1){
		        	total = total + 1;
			}
		}
		return total;
	}
	void freq(){
		for(int i = 0; i < cap; i++){
			if(arr[i][0] != -1){
				cout<<arr[i][0]<<" : "<<arr[i][1]<<endl;		
			}
		}
	}
	
};
int main(){
	int n;
	cout<<"Enter the value of n"<<endl;
	cin >> n;
	int arr[n];
	cout<<"Enter the values for the array"<<endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}        	
	cout<<"Elements of the array"<<endl;
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";	
	}
	cout<<endl;
	HashMap hm(50);
	for(int i = 0; i < n; i++){
		hm.insert(arr[i]);
	}
	cout<<endl;
	cout<<"Total number of distinct elements"<<endl;
	cout<<hm.count()<<endl;
	cout<<"Frequncy"<<endl;
	hm.freq();
	return 0;
}