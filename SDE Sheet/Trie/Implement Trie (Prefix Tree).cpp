class Trie {
private:
    class Node {
        private:
            Node* links[26];
            bool flag = false;

        public:
            bool containsLink(char ch) {
                return (links[ch - 'a'] != NULL);
            }
            void put(char ch, Node* node) {
                links[ch - 'a'] = node;
            }
            Node* getLink(char ch) {
                return links[ch - 'a'];
            }
            void setEnd() {
                flag = true;
            }
            bool getEnd() {
                return flag;
            }
    };
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsLink(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->getLink(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsLink(word[i])) {
                return false;
            }
            node = node->getLink(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsLink(word[i])) {
                return false;
            }
            node = node->getLink(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */