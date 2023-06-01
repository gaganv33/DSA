#include<bits/stdc++.h>
using namespace std;

int Gcd(int a, int b);

int main(){
	int a, b;
	cin >> a >> b;
	
	int value = Gcd(a, b);
	cout << value << endl;
	int lcm = (a * b) / value;
	cout << lcm << endl;	
	return 0;	
}

// Using Euclid ALgorithm
int Gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return Gcd(b, a % b);
	}
}