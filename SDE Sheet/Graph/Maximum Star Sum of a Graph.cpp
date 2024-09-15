class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        map<int, set<pair<int, int>, greater<pair<int, int>>>> v;
        for(int i = 0; i < vals.size(); i++) {
            v[i] = set<pair<int, int>, greater<pair<int, int>>> ();
        }
        for(auto x: edges) {
            v[x[0]].insert({vals[x[1]], x[1]});
            v[x[1]].insert({vals[x[0]], x[0]});
        }
        int ans = INT_MIN;

        for(auto x: v) {
            int sum = vals[x.first];
            int temp = k;
            ans = max(ans, sum);
            for(auto y : x.second) {
                if(temp == 0) break;
                sum += y.first;
                ans = max(ans, sum);
                temp--;
            }
        }

        return ans;
    }
};