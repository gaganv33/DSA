class Node {
private:
    Node* links[26];
    bool flag = false;
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
    bool getFlag() {
        return flag;
    }
    void setFlag() {
        flag = true;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto x : word) {
            if(!node->contains(x)) {
                node->put(x, new Node());
            }
            node = node->get(x);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        return solve(0, word, root);
    }
    
    bool solve(int index, string &word, Node* node) {
        if(node == NULL) return false;
        if(index >= word.size()) return node->getFlag();

        if(word[index] == '.') {
            for(char c = 'a' ; c <= 'z'; c++) {
                if(solve(index + 1, word, node->get(c))) return true;
            }
        }
        else {
            if(node->contains(word[index]) && solve(index + 1, word, node->get(word[index]))) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
