#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i = 0; i < t; i++){
	    int n, k, v;
	    cin>>n>>k>>v;
	    int array[100];
	    for(int j = 0; j < n; j++){
	        cin>>array[j];
	    }
	    
	    // Finding the sum of the arary
	    int sum = 0;
	    for(int j = 0; j < n; j++){
	        sum = sum + array[j];
	    }
	    int total = n + k;
	    int value = (total * v) - sum;
	    // Checking if value is less than 0
	    if(value < 0){
	        cout<< -1<<endl;
	    }
	    else{
	        if(value%k == 0){
	            int res = static_cast<int>(value / k);
	            cout<<res<<endl;
	        }
	        else{
	            cout<< -1<<endl;
	        }
	    }
	}
	return 0;
}
