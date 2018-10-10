#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* next[26];
        bool have;
        string str;
        TrieNode(bool h = false) : have(h) {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* root, string s) {
        for (auto c : s) {
            if (root->next[c - 'a'] == nullptr) {
                root->next[c - 'a'] = new TrieNode();
            }
            root = root->next[c - 'a'];
        }

        root->str = s;
        root->have = true;
    }

    vector<string> getkEditDistance(vector<string>& words,
                                    string target,
                                    int k) {
        TrieNode* root = new TrieNode();
        for (auto w : words) {
            insert(root, w);
        }

        vector<string> res;
        int n = target.size();
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }

        search(root, res, k, target, dp);
        return res;
    }

    void search(TrieNode* root,
                vector<string>& res,
                int k,
                string target,
                vector<int> dp) {
        int n = target.size();
        if (root->have && dp[n] <= k) {
            res.push_back(root->str);
        }

        vector<int> next_dp(n + 1);

        for (int ch = 0; ch < 26; ++ch) {
            if (root->next[ch] != nullptr) {
                next_dp[0] = dp[0] + 1;
                for (int i = 1; i <= n; ++i) {
                    if (target[i - 1] - 'a' == ch) {
                        next_dp[i] = dp[i - 1];
                    } else {
                        next_dp[i]
                            = min(dp[i - 1], min(dp[i], next_dp[i - 1])) + 1;
                    }
                }
                search(root->next[ch], res, k, target, next_dp);
            }
        }
    }
};

int main() {
    vector<string> words = {"abc", "abd", "abcd", "adc"};
    string target = "ac"; // "abc", "adc" when k = 1
    int k = 1;

    Solution s;
    vector<string> res = s.getkEditDistance(words, target, k);
    for (auto w : res) {
        cout << w << endl;
    }

    return 0;
}
