class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = 1e9;
        int ans = 0;
        for(auto x: prices) {
            minVal = min(minVal, x);
            ans = max(ans, x - minVal);
        }
        return ans;
    }
};