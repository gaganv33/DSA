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
    TreeNode* solve(TreeNode* root, int startValue, int destValue) {
        if(root == NULL) return NULL;
        if(root->val == startValue || root->val == destValue) return root;

        TreeNode* left = solve(root->left, startValue, destValue);
        TreeNode* right = solve(root->right, startValue, destValue);

        if(left == NULL && right == NULL) return NULL;
        else if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
    bool rootToStart(TreeNode* root, int value, string &s) {
        if(root == NULL) return false;
        if(root->val == value) return true;

        s += 'U';
        if(rootToStart(root->left, value, s)) return true;
        if(rootToStart(root->right, value, s)) return true;
        s.pop_back();
        return false;
    }
    bool rootToEnd(TreeNode* root, int value, string &s) {
        if(root == NULL) return false;
        if(root->val == value) return true;

        s += 'L';
        if(rootToEnd(root->left, value, s)) return true;
        s.pop_back();
        s += 'R';
        if(rootToEnd(root->right, value, s)) return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node = solve(root, startValue, destValue);
        string start = "";
        string end = "";
        rootToStart(node, startValue, start);
        rootToEnd(node, destValue, end);
        return start + end;
    }
};