#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        partition(res, temp, 0, s);
        return res;
    }

    void partition(vector<vector<string>>& res,
                   vector<string>& temp,
                   int start,
                   string& s) {
        if (start == s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                partition(res, temp, i + 1, s);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
/*
 aaa
 012
 */

int main() {
    string test = "aaa";
    Solution s;
    auto res = s.partition(test);
    for (auto row : res) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
