/*
Given a string, sort it in decreasing order based on the frequency of
characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer. Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_count;
        for (auto c : s) {
            char_count[c]++;
        }

        vector<pair<int, char>> counts;
        for (auto cc : char_count) {
            counts.push_back(make_pair(cc.second, cc.first));
        }
        sort(counts.begin(), counts.end(),
             [](const pair<int, char>& c1, const pair<int, char>& c2) {
                 return c1.first > c2.first;
             });

        string res;
        for (auto c : counts) {
            res += string(c.first, c.second);
        }

        return res;
    }
};

class Solution2 {
public:
    struct compare {
        bool operator()(const pair<int, char>& p1, const pair<int, char>& p2) {
            return p1.first < p2.first;
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> char_count;
        for (auto c : s) {
            char_count[c]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, compare> q;
        for (auto cc : char_count) {
            q.push(make_pair(cc.second, cc.first));
        }

        string res;
        while (!q.empty()) {
            res += string(q.top().first, q.top().second);
            q.pop();
        }

        return res;
    }
};

class Solution3 {
public:
    string frequencySort(string s) {
        vector<int> fre(128, 0);
        for (auto c : s) {
            fre[c]++;
        }

        sort(s.begin(), s.end(), [&](char l, char r) {
            return fre[l] > fre[r] || (fre[l] == fre[r] && l < r);
        });

        return s;
    }
};

class Solution4 {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fre;
        for (auto c : s) {
            fre[c]++;
        }

        vector<string> bucket(s.size() + 1, "");
        for (auto item : fre) {
            bucket[item.second] += string(item.second, item.first);
        }

        string res;
        for (int i = s.size(); i >= 0; --i) {
            res += bucket[i];
        }

        return res;
    }
};
