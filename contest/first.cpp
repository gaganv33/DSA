#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin >> t;
   

   for(int i = 0; i < t; i++) {
      int n, x, y;
      cin >> n >> x >> y;

      vector<int> v;
      for(int j = 0; j < n; j++) {
         int value;
         cin >> value;
         v.push_back(value);
      }

      int count = 0;      
      for(int j = 0; j < n; j++) {
         for(int k = j + 1; k < n; k++) {
            if((v[j] + v[k]) % x == 0 && (v[j] - v[k]) % y == 0) {
               count++;         
            }
         }
      }
      cout << count << endl;
   }

   return 0;
}