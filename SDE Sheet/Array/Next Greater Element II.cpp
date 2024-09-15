class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        n = nums.size();
        stack<int> s;
        vector<int> ans (n);
        // starting from the right to left
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if(s.size() == 0) ans[i] = -1;
            else ans[i] = s.top();
            s.push(nums[i]);
        }
        vector<int> a;
        for(int i = 0; i < (n / 2); i++) {
            a.push_back(ans[i]);
        }
        return a;
    }
};