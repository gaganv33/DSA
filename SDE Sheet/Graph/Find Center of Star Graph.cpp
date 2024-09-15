class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans (n + 2, 0);
        for(auto x : edges) {
            ans[x[0]]++;
            ans[x[1]]++;
        }
        for(int i = 0; i < (n + 2); i++) {
            if(ans[i] > 1) return i;
        }
        return 0;
    }
};