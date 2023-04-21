#include<iostream>
#include <algorithm>
using namespace std;

void printNto1(int n);
void print1toN(int n);
int sumNaturalNumbers(int n);
bool isPalindrome(string &str, int start, int end);
int sumOFDigits(int n);
void subString(string &str, string curr, int i);
int Rope(int n, int a, int b, int c);
int Max(int a, int b, int c);

int main(){
    cout<<"Enter the value for n\n";
    int n;
    cin>>n;
    cout<<"Printing from N to 1"<<endl;
    printNto1(n);
    cout<<"Printing from 1 to N"<<endl;
    print1toN(n);
    cout<<"Sum of the first "<<n<<" natural numbers are\n";
    cout<<sumNaturalNumbers(n)<<endl;
    string str;
    cout<<"Enter a string"<<endl;
    cin>>str;
    cout<<isPalindrome(str, 0, str.length() - 1)<<endl;
    int m;
    cout<<"Enter the value of m"<<endl;
    cin>>m;
    cout<<"The sum of the digits of "<<m<<" are"<<endl;
    cout<<sumOFDigits(m)<<endl;
    cout<<"All the possible sub strings are"<<endl;
    string curr = "";
    subString(str, curr, 0);
    cout<<"Cutting rope"<<endl;
    int a, b, c, o;
    cin>>o>>a>>b>>c;
    cout<<Rope(o, a, b, c)<<endl;
    return 0;
}

void printNto1(int n){
    if(n == 0){
        return;
    }
    cout<<n<<endl;
    printNto1(n - 1);
}
void print1toN(int n){
    if(n == 0){
        return;
    }
    print1toN(n - 1);
    cout<<n<<endl;
}
int sumNaturalNumbers(int n){
    if(n == 1){
        return 1;
    }
    return n + sumNaturalNumbers(n - 1);
}
bool isPalindrome(string &str, int start, int end){
    if(start >= end){
        return true;
    }
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}
int sumOFDigits(int n){
    if(n == 0){
        return 0;
    }
    return (n % 10) + sumOFDigits(n / 10);
}
void subString(string &str, string curr, int i){
    if(i == str.length()){
        cout<<curr<<endl;
        return;
    }
    subString(str, curr, i + 1);
    subString(str, curr + str[i], i + 1);
}
int Max(int a, int b, int c){
	if(a > b && a > c){
		return a;
	}
	else if(b > a && b > c){
		return b;
	}
	return c;
}
int Rope(int n, int a, int b, int c){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return -1;
    }
    int res = Max(Rope(n - a, a ,b, c), Rope(n - b, a ,b, c), Rope(n - c, a ,b, c));
    if(res < 0){
        return -1;
    }
    return res + 1;
}
