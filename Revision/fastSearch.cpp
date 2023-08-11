#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	cin >> k;
	while(k--){
		int f, s;
		cin >> f >> s;
		
		int l = -1;
		int h = n;
		while(h > (l + 1)){
			int m = (h + l) / 2;
			if(a[m] < f){
				l = m;
			}
			else{
				h = m;				
			}
		}
		//cout << l << " "<< h << endl;
		int indexfirst = h;
		
		l = -1;
		h = n;
		while(h > (l + 1)){
			int m = (h + l) / 2;
			if(a[m] <= s){
				l = m;
			}
			else{
				h = m;
			}
		}
		int indexsecond = h;
		//cout << l << " " << h << endl;
		if(indexfirst == indexsecond){
			cout << 0 << endl;
		}
		else{
			cout << indexsecond - indexfirst << endl;
		}
	}	
	return 0;
}