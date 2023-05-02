#include<bits/stdc++.h>
using namespace std;

struct Guest{
	int start, end, num;
};

bool CompareGuest(Guest g1, Guest g2){
	return (g1.start < g2.start);
}

int main(){
	int n;
	cin >> n;
	Guest arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i].start >> arr[i].end;
		arr[i].num = 1;
	}
	sort(arr, arr + n, CompareGuest);
	
	int res = 0;
	for(int i = 1; i < n; i++){
		if(arr[res].end >= arr[i].start){
			arr[res].start = min(arr[res].start, arr[i].start);
			arr[res].end = max(arr[res].end, arr[i].end);
			arr[res].num = arr[res].num + 1;
		}
		else{
			res++;
			arr[res] = arr[i];
		}
	}
	
	for(int i = 0; i <= res; i++){
		cout << arr[i].start << " " << arr[i].end << " " << arr[i].num << endl;
	}
	return 0;
}