/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing
only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WordDictionary {
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
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next[word[i] - 'a'] == nullptr) {
                cur->next[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[word[i] - 'a'];
        }

        cur->have = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* cur = root;
        return search(word, cur, 0);
    }

    bool search(const string& word, TrieNode* cur, int pos) {
        if (cur == nullptr) {
            return false;
        }

        for (int i = pos; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int ch = 0; ch < 26; ++ch) {
                    if (search(word, cur->next[ch], i + 1)) {
                        return true;
                    }
                }
                return false;
            }

            if (cur->next[word[i] - 'a'] == nullptr) {
                return false;
            }

            cur = cur->next[word[i] - 'a'];
        }

        return cur->have;
    }

    ~WordDictionary() { delete root; }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() {}
