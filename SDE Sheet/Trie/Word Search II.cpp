class Node {
private:
    Node* links[26];
    bool flag = 0;
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
    void setFlag() {
        flag = true;
    }
    int getFlag() {
        return flag;
    }
};

class Solution {
private:
    vector<int> x = {1, 0, -1, 0};
    vector<int> y = {0, 1, 0, -1};
public:
    void insert(Node* node, string s) {
        for(auto x: s) {
            if(!node->contains(x)) {
                node->put(x, new Node());
            }
            node = node->get(x);
        }
        node->setFlag();
    }
    void solve(int i, int j, int m, int n, string &s, Node* node, vector<vector<char>> &board, vector<vector<bool>> &visit,
        set<string> &ans) {
        if(node == NULL) return;
        if(!node->contains(board[i][j])) return;

        visit[i][j] = true;
        s += board[i][j];

        node = node->get(board[i][j]);
        if(node->getFlag()) ans.insert(s);

        for(int k = 0; k < 4; k++) {
            int newI = i + x[k];
            int newJ = j + y[k];

            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && !visit[newI][newJ]) {
                solve(newI, newJ, m, n, s, node, board, visit, ans);
            }
        }

        visit[i][j] = false;
        s.pop_back();

        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();

        for(auto x : words) {
            insert(root, x);
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visit (m, vector<bool> (n, false));
        set<string> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string s = "";
                solve(i, j, m, n, s, root, board, visit, ans);
            }
        }
        vector<string> a;
        for(auto x : ans) {
            a.push_back(x);
        }

        return a;
    }
};