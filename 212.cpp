#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* next[26];
        string word;
        TrieNode(string w = "") : word(w) {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };

    void buildTrie(vector<string>& words, TrieNode* root) {
        for (auto&& word : words) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); ++i) {
                if (cur->next[word[i] - 'a'] == nullptr)
                    cur->next[word[i] - 'a'] = new TrieNode();
                cur = cur->next[word[i] - 'a'];
            }
            cur->word = word;
        }
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> res;
        buildTrie(words, root);
        const int m = board.size();
        const int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(root, board, res, i, j, m, n);
            }
        }
        return res;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(TrieNode* root,
             vector<vector<char>>& board,
             vector<string>& res,
             int i,
             int j,
             const int& m,
             const int& n) {
        char x = board[i][j];
        if (x == '*')
            return;
        TrieNode* tmp = root->next[board[i][j] - 'a'];
        if (tmp == nullptr)
            return;
        if (tmp->word != "") { // found one.
            res.push_back(root->next[board[i][j] - 'a']->word);
            tmp->word = ""; // no duplicate.
            // no return, move forward.
        }
        board[i][j] = '*';
        for (auto&& d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n)
                dfs(tmp, board, res, x, y, m, n);
        }
        board[i][j] = x;
        return;
    }
};

class Solution2 {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        string str;
    };

    void insert(TrieNode* root, string s) {
        for (auto c : s) {
            if (!root->next.count(c)) {
                root->next[c] = new TrieNode();
            }
            root = root->next[c];
        }

        root->str = s;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int m = board.size();
        if (!m) {
            return {};
        }
        int n = board[0].size();
        vector<string> res;

        TrieNode* root = new TrieNode();
        for (auto w : words) {
            insert(root, w);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->next.count(board[i][j])) {
                    search(root->next[board[i][j]], res, board, i, j);
                }
            }
        }

        return res;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void search(TrieNode* root,
                vector<string>& res,
                vector<vector<char>>& board,
                int i,
                int j) {
        if (root->str != "") {
            res.push_back(root->str);
            root->str = "";
        }

        char backup = board[i][j];
        board[i][j] = '#';
        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()
                || !root->next.count(board[x][y])) {
                continue;
            }

            search(root->next[board[x][y]], res, board, x, y);
        }
        board[i][j] = backup;
    }
};

int main() {}
