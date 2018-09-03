// Given a non-empty list of words, return the k most frequent elements.
//
// Your answer should be sorted by frequency from highest to lowest. If two
// words have the same frequency, then the word with the lower alphabetical
// order comes first.
//
// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
// "is"], k = 4 Output: ["the", "is", "sunny", "day"] Explanation: "the", "is",
// "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

class Solution {
public:
    struct comp {
        bool operator()(pair<string, int> i, pair<string, int> j) {
            return i.second != j.second ? i.second > j.second
                                        : i.first < j.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto w : words) {
            m[w]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> q;
        for (auto word : m) {
            q.push(make_pair(word.first, word.second));
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
