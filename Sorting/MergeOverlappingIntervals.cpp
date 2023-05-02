#include<bits/stdc++.h>
using namespace std;

struct Interval{
	int start, end;
};

bool CompareInterval(Interval i1, Interval i2){
	return (i1.start < i2.start);
}

int main(){
	int n;
	cin >> n;
	Interval arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i].start >> arr[i].end;
	}
	sort(arr, arr + n, CompareInterval);
	
	int res = 0;
	for(int i = 1; i < n; i++){
		if(arr[res].end >= arr[i].start){
			arr[res].start = min(arr[res].start, arr[i].start);
			arr[res].end = max(arr[res].end, arr[i].end);
		}
		else{
			res++;
			arr[res] = arr[i];
		}
	}
	for(int i = 0; i <= res; i++){
		cout << arr[i].start << " " << arr[i].end << endl;
	}
	return 0;
}