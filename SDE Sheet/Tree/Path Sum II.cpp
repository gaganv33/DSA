/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int> &v, multiset<vector<int>> &ans) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            if(root->val == targetSum) {
                v.push_back(root->val);
                ans.insert(v);
                v.pop_back();
            }
            return;
        }

        targetSum -= root->val;
        v.push_back(root->val);

        solve(root->left, targetSum, v, ans);
        solve(root->right, targetSum, v, ans);

        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        multiset<vector<int>> ans;
        vector<int> v;
        solve(root, targetSum, v, ans);
        
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};