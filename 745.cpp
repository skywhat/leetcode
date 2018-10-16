// Given many words, words[i] has weight i.
//
// Design a class WordFilter that supports one function, WordFilter.f(String
// prefix, String suffix). It will return the word with given prefix and suffix
// with maximum weight. If no word exists, return -1.
//
// Examples:
// Input:
// WordFilter(["apple"])
// WordFilter.f("a", "e") // returns 0
// WordFilter.f("b", "") // returns -1
// Note:
// words has length in range [1, 15000].
// For each test case, up to words.length queries WordFilter.f may be made.
// words[i] has length in range [1, 10].
// prefix, suffix have lengths in range [0, 10].
// words[i] and prefix, suffix queries consist of lowercase letters only.

class WordFilter {
public:
    struct TrieNode {
        int weight;
        unordered_map<char, TrieNode*> next;
        TrieNode(int w = 0) : weight(w) {}
    };

    TrieNode* root;

    void insert(TrieNode* root, string word, int weight) {
        for (auto c : word) {
            if (!root->next.count(c)) {
                root->next[c] = new TrieNode();
            }

            root = root->next[c];
            root->weight = weight;
        }
    }

    int search(TrieNode* root, string s) {
        for (auto c : s) {
            if (!root->next.count(c)) {
                return -1;
            }
            root = root->next[c];
        }

        return root->weight;
    }

    WordFilter(vector<string> words) {
        root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                insert(root,
                       words[i].substr(words[i].size() - j, j) + "#" + words[i],
                       i);
            }
        }
    }

    int f(string prefix, string suffix) {
        return search(root, suffix + "#" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
