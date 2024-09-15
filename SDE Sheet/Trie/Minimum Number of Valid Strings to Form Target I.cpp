class Node {
private:
    Node* links[26];
public:
    bool contains(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
public:
    void insert(Node* node, string s) {
        for(int i = 0; i < s.size(); i++) {
            if(!node->contains(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
    }
    int search(Node* node, int index, string target) {
        while(node != NULL && index < target.size()) {
            if(!node->contains(target[index])) return index;
            node = node->get(target[index]);
            index++;
        }
        return index;
    }
    int solve(int index, Node* root, string &target, vector<int> &dp) {
        if(index >= target.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int newIndex = search(root, index, target);
        if(index == newIndex) return 1e9;
        
        int ans = 1e9;

        for(int i = index + 1; i <= newIndex; i++) {
            ans = min(ans, solve(i, root, target, dp) + 1);
        }

        return dp[index] = ans;
    }
    int minValidStrings(vector<string>& words, string target) {
        Node* root = new Node();
        for(auto x: words) {
            insert(root, x);
        }
        int n = target.size();
        vector<int> dp (n, -1);
        int ans = solve(0, root, target, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }   
};
