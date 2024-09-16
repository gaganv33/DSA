#include <bits/stdc++.h>

class Node {
private:
    Node* links[26];
    int count = 0;
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
    void incrementCount() {
        count++;
    }
    int getCount() {
        return count;
    }
};

void insert(Node* node, string s) {
    for(auto x : s) {
        if(!node->contains(x)) {
            node->put(x, new Node());
        }
        node = node->get(x);
        node->incrementCount();
    }
}

void solve(Node* node, int n, string &s, string &ans) {
    if(s.size() > ans.size()) {
        ans = s;
    }
    for(char c = 'a' ; c <= 'z'; c++) {
        if(node->contains(c)) {
            Node* temp = node;
            temp = temp->get(c);
            if(temp->getCount() == n) {
                s += c;
                solve(temp, n, s, ans);
                s.pop_back();
            }
        }
    }
} 

string longestCommonPrefix(vector<string> &arr, int n)
{
    Node* root = new Node();

    for(auto x : arr) {
        insert(root, x);
    }
    string ans = "";
    string s = "";
    solve(root, n, s, ans);
    return ans;
}
