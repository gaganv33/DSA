#include<iostream>
using namespace std;

struct HashMap{
  int *arr;
  int cap;
  int size;
  HashMap(int c){
    cap = c;
    size = 0;
    for(int i = 0 ; i < cap ; i++){
      arr[i] = -100;
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
    int index = 1;
    int i = h;
    while(arr[i] != -100){
      if(arr[i] == key){
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
  int insert(int key){
    if(size == cap)
	return 0;
    int h = hash1(key);
    int offset = hash2(key);
    int index = 1;
    int i = h;
    while(arr[i] != -100 && arr[i] != -101 && arr[i] != key){
      i = (h + (index * offset)) % cap;
      index = index + 1;
    }
    if(arr[i] == key){
      return 0;  
    }
    else{
      arr[i] = key;
      size = size + 1;
      return 1;
    }
  }
  int erase(int key){
    int h = hash1(key);
    int offset = hash2(key);
    int index = 1;
    int i = h;
    while(arr[i] != -100){
      if(arr[i] == key){
        arr[i] = -101;
        size = size - 1;
        return 1;
      }
      else{
        i = (h + (index * offset)) % cap;
        index = index + 1;
      }
      if(i == h){
        return 0;
      }
    }
  } 
  int* print(){
    return arr;
  }
};

int main(){
  cout<<"Subarray with 0 sum"<<endl;
  cout<<"Total number of elements in the array"<<endl;
  int n;
  cin>>n;
  HashMap hm(50);
  int arr[50];
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  int pre_sum = 0;
  int found = 0;
  for(int i = 0 ; i < n; i++){
    pre_sum = pre_sum + arr[i];
    if(hm.insert(pre_sum) == 0 || pre_sum == 0){
      cout<<"Yes"<<endl; 
      found = 1;
      break;
    }
  }
  if(found == 0){
    cout<<"No"<<endl;
  }              
  return 0;
}