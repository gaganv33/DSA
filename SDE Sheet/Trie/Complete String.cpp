#include <bits/stdc++.h> 
class Node{
private:
    Node* links[26];
    bool flag = false;
public:
    bool contains(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    bool getFlag() {
        return flag;
    }
    void setFlag() {
        flag = true;
    }
};
void insertWord(Node* root, string a) {
    for(int i = 0; i < a.size(); i++) {
        if(!root->contains(a[i])) {
            root->put(a[i], new Node());
        }
        root = root->get(a[i]);
    }
    root->setFlag();
}

bool search(Node* root, string a) {
    for(int i = 0; i < a.size(); i++) {
        root = root->get(a[i]);
        if(!root->getFlag()) {
            return false;
        }
    }
    return true;
}

string completeString(int n, vector<string> &a){
    Node* root = new Node();
    for(auto x : a) {
        insertWord(root, x);
    }
    string ans = "";

    for(auto x : a) {
        bool val = search(root, x);
        if(val) {
            if(x.size() > ans.size()) {
                ans = x;
            }
            else if(x.size() == ans.size()) {
                ans = min(ans, x);
            }
        }
    }
    
    if(ans == "") return "None";
    return ans;
}