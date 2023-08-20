#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	unordered_map<char, int> m;
	for(int i = 0; i < n; i++){
		m[str[i]]++;
	}
	int count = m.size();
	
	int start = 0;
	int ans = INT_MAX;
	m  = unordered_map<char, int> ();
	
	for(int end = 0; end < n; end++){
		m[str[end]]++;
		while(m.size() >= count && start <= end){
			m[str[start]]--;
			if(m[str[start]] == 0){
				m.erase(str[start]);
			}
			if(m.size() < count){
				m[str[start]]++;
				break;
			}
			start++;
		}
		if(m.size() == count){
			ans = min(ans, (int)(end - start + 1));
		}
	}
	cout << ans << "\n";
	return 0;
}