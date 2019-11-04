#include <iostream>
#include <string>
#include <vector>

using namespace std;

// recursive
class Solution {
public:
    vector<string> digit_to_letters
        = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return {};
        }

        combine("", res, 0, digits);
        return res;
    }

    void combine(string temp, vector<string>& res, int pos, string digits) {
        if (pos >= digits.size()) {
            res.push_back(temp);
            return;
        }

        for (auto c : digit_to_letters[digits[pos] - '0']) {
            combine(temp + c, res, pos + 1, digits);
        }
    }
};

// iterative
class Solution2 {
public:
    vector<string> digit_to_letters
        = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return {};
        }

        res.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> temp;
            for (auto c : digit_to_letters[digits[i] - '0']) {
                for (int i = 0; i < res.size(); ++i) {
                    temp.push_back(res[i] + c);
                }
            }
            res = temp;
        }

        return res;
    }
};

int main() {}
