#include <bits/stdc++.h> 
class Node{
private:
    Node* links[26];
    int countPre = 0;
    int countEnd = 0;
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
    void incrementCountPre() {
        countPre++;
    }
    void incrementCountEnd() {
        countEnd++;
    }
    void decrementCountPre() {
        countPre--;
    }
    void decrementCountEnd() {
        countEnd--;
    }
    int getCountEnd() {
        return countEnd;
    }
    int getCountPre() {
        return countPre;
    }
};

class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementCountPre();
        }
        node->incrementCountEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getCountEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getCountPre();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->decrementCountPre();
        }
        node->decrementCountEnd();
    }
};
