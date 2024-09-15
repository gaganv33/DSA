#include <bits/stdc++.h>
class Node{
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
bool check(Node* root, string s) {
    for(int i = 0; i < s.size(); i++) {
        if(!root->contains(s[i])) {
            root->put(s[i], new Node());
            return false;
        }
        root = root->get(s[i]);
    }
    return true;
}
int countDistinctSubstrings(string &s)
{
    Node* root = new Node();
    int ans = 0;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        string t = "";
        for(int j = i; j < n; j++) {
            t += s[j];
            if(!check(root, t)) {
                ans++;
            }
        }
    }

    return (ans + 1);
}