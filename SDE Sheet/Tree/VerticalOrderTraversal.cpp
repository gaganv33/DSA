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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> v;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            map<int, vector<int>> m;
            int n = q.size();

            for(int i = 0; i < n; i++) {
                pair<TreeNode*, int> p = q.front();
                q.pop();
                TreeNode* node = p.first;
                int shift = p.second;

                m[shift].push_back(node->val);

                if(node->left != NULL) {
                    q.push({node->left, shift - 1});
                }
                if(node->right != NULL) {
                    q.push({node->right, shift + 1});
                }
            }

            for(auto &x: m) {
                sort(x.second.begin(), x.second.end());
                for(auto y : x.second) {
                    v[x.first].push_back(y);   
                }   
            }
        }

        vector<vector<int>> ans;
        for(auto x : v) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
