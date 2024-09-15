/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        // if root is p or q, then return the root
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if left is null and right is null, then return null. (Nodes p and q are not present in left and right subtree)
        if(left == NULL && right == NULL) return NULL;
        // if left is null, then both the nodes are in the right subtree.
        else if(left == NULL) return right;
        // if right is null, then both the nodes are in the left subtree.
        else if(right == NULL) return left;
        // is left is not null and right is also not null, then the current nodes is the LCA.
        return root;
    }
};