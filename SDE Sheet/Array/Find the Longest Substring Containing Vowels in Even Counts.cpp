class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> m;
        m[0] = -1;
        int val = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') {
                val = val ^ (1 << 0);
            }
            else if(s[i] == 'e') {
                val = val ^ (1 << 1);
            }
            else if(s[i] == 'i') {
                val = val ^ (1 << 2);
            }
            else if(s[i] == 'o') {
                val = val ^ (1 << 3);
            }
            else if(s[i] == 'u') {
                val = val ^ (1 << 4);
            }
            if(m.find(val) != m.end()) {
                ans = max(ans, i - m[val]);
            }
            else m[val] = i;
        }
        return ans;
    }
};
