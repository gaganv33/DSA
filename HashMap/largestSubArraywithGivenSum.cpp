#include<iostream>
using namespace std;
#define MAX 50

struct HashMap{
	int arr[MAX][2];
	int size, cap;
	HashMap(int c){
		cap = c;
		size = 0;
		for(int i = 0; i < cap; i++){
			arr[i][0] = arr[i][1] = -101;
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
		// returns the position of the key in the hash map
		int h = hash1(key);
		int offset = hash2(key);
		int index = 1;
		int i = h;
		while(arr[i][0] != -101){
			if(arr[i][0] == key){
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
	void insert(int key, int pos){
		// return the maximum value 
		if(size == cap){
			return;
		}
		int h = hash1(key);
		int offset = hash2(key);
		int index = 1;
		int i = h;
		while(arr[i][0] != -101 && arr[i][0] != key){
			i = (h + (index * offset)) % cap;
			index = index + 1;
		}
		if(arr[i][0] == key){
			return;
		}
		else{
			arr[i][0] = key;
			arr[i][1] = pos;
			size = size + 1;
			return;
		}			
	}        
        int getPos(int index){
                return arr[index][1];
        }
};

int main(){
	int n, sum;
	cin >> n >> sum;
	int num[n];
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	int presum = 0;
	int res = 0;
        HashMap hm(MAX);
	for(int i = 0; i < n; i++){
		presum = presum + num[i];
		if(presum == sum)
			res = i + 1;
		hm.insert(presum, i);
		int index = hm.search(presum - sum);
                if(index != -1){
                        int second = hm.getPos(presum - sum);
                        res = max(res, i - second);
                }
	}
	cout << res << endl;
        return 0;
}