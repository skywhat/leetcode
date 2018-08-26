#include <iostream>
#include <string>

using namespace std;

class Trie {
public:
    struct TrieNode {
        TrieNode* next[26];
        bool have;
        TrieNode(bool h = false) : have(h) {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };

    /** Initialize your data structure here. */
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next[word[i] - 'a'] == nullptr) {
                cur->next[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[word[i] - 'a'];
        }

        cur->have = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next[word[i] - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[word[i] - 'a'];
        }

        return cur->have;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (cur->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[prefix[i] - 'a'];
        }

        return true;
    }

    ~Trie() { delete root; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    Trie obj;
    obj.insert("abc");
    cout << obj.search("ab") << endl;
    cout << obj.search("abc") << endl;

    return 0;
}
