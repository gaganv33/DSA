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
    pair<int, int> solve(TreeNode* root, int &ans) {
        if(root == NULL) return {INT_MIN, -1};

        pair<int, int> left = solve(root->left, ans);
        pair<int, int> right = solve(root->right, ans);

        if(left.first == INT_MIN && right.first == INT_MIN) {
            ans = max(ans, 1);
            return {root->val, 1};
        }
        ans = max(ans, max(left.second, right.second));
        if(root->val == left.first && root->val == right.first) {
            ans = max(ans, 1 + left.second + right.second);
        }
        pair<int, int> p = {root->val, 1};
        if(left.first == root->val && (1 + left.second) > p.second) {
            ans = max(ans, 1 + left.second);
            p.first = left.first;
            p.second = 1 + left.second;
        }
        if(right.first == root->val && (1 + right.second) > p.second) {
            ans = max(ans, 1 + right.second);
            p.first = right.first;
            p.second = 1 + right.second;
        }
        return p;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        if(ans == 0) return 0;
        return ans - 1;
    }
};