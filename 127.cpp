#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> toVisit;
        addNextWord(words, toVisit, beginWord);
        int dist = 2;
        while (!toVisit.empty()) {
            int size = toVisit.size();
            while (size--) {
                string next = toVisit.front();
                toVisit.pop();
                if (next == endWord) {
                    return dist;
                }
                addNextWord(words, toVisit, next);
            }
            dist++;
        }

        return 0;
    }

    void addNextWord(unordered_set<string>& words,
                     queue<string>& toVisit,
                     string begin) {
        for (int i = 0; i < begin.size(); ++i) {
            char x = begin[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == x) {
                    continue;
                }

                begin[i] = ch;
                auto it = words.find(begin);
                if (it != words.end()) {
                    toVisit.push(begin);
                    words.erase(it);
                }
            }
            begin[i] = x;
        }
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
