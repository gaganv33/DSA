#include<iostream>
using namespace std;

struct HashMap{
	int *arr;
	int cap, size;
	HashMap(int c){
		cap = c;
		size = 0;
		arr[cap];
		for(int i = 0; i < cap; i++){
			arr[i] = -1;
		}
	}
	int hash1(int key){
		return (key % cap);
	}
	int hash2(int key){
		int new_cap = cap - 1;
		return (new_cap - (key % new_cap));
	}
	int search(int key){
		int h = hash1(key);
		int index = 0;
		int offset = hash2(key);
		int i = h;
		while(arr[i] != -1){
			if(arr[i] == key){
				return i;
			}
			else{
				i = (h + (index * offset)) % cap;
				index = index + 1;
			}
			if(i == h){
				return -1;
			}
		}
		return -1;
	}
	int insert(int key){
		if(size == cap){
			return -1;
		}
		int h = hash1(key);
		int index = 1;
		int offset = hash2(key);
		int i = h;
		while(arr[i] != -1 && arr[i] != -2 && arr[i] != key){
			i = (h + (index * offset)) % cap;
			index = index + 1;
		}
		if(arr[i] == key){
			return -1;
		}
		else{
			arr[i] = key;
			size = size + 1;
			return 1;
		}
	}
	int *get(){
		return arr;
	}
};

int main(){
	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	HashMap hm(50);
	int presum = 0;
	for(int i = 0; i < n; i++){
		presum = presum + arr[i];
		hm.insert(presum);
		int value = hm.search(presum - sum);
		if(value != -1 || presum == sum){
			cout << "True" << endl;
			return 0;
		}
	}
	cout << "False" << endl;
	return 0;
}