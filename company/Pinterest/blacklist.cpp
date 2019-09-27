#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct TrieNode {
        map<string, TrieNode*> next;
        bool end;
        TrieNode(bool e = false) : end(e) {}
    };

    TrieNode* root;
    Solution() { root = new TrieNode(); }

    void buildTrie(vector<string>& blacklist) {
        for (auto s : blacklist) {
            TrieNode* cur = root;
            istringstream ss(s);
            string temp;
            while (ss >> temp) {
                if (!cur->next.count(temp)) {
                    cur->next[temp] = new TrieNode();
                }
                cur = cur->next[temp];
            }
            cur->end = true;
        }
    }

    vector<string> searchBlackSentences(vector<string> sentences,
                                        vector<string> blacklist) {
        vector<string> res;
        buildTrie(blacklist);

        for (auto s : sentences) {
            TrieNode* cur = root;

            istringstream ss(s);
            string temp;
            vector<string> wordlist;
            while (ss >> temp) {
                wordlist.push_back(temp);
            }

            for (int i = 0; i < wordlist.size(); ++i) {
                if (startWith(wordlist, cur, i)) {
                    res.push_back(s);
                    break;
                }
            }
        }

        return res;
    }

    bool startWith(vector<string>& wordlist, TrieNode* cur, int pos) {
        for (int i = pos; i < wordlist.size(); ++i) {
            if (!cur->next.count(wordlist[i])) {
                return cur->end;
            }
            cur = cur->next[wordlist[i]];
        }

        return cur->end;
    }
};

int main() {
    vector<string> blacklist = {"porn", "world war I"};
    vector<string> sentences = {
        "I love porn", // get
        "I love world war II",
        "I love world war",
        "world war I I love",      // get
        "porn world war II world", // get
    };

    Solution s;
    vector<string> res = s.searchBlackSentences(sentences, blacklist);
    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
