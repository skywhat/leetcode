// Given an encoded string, return it's decoded string.
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.
//
// You may assume that the input string is always valid; No extra white spaces,
// square brackets are well-formed, etc.
//
// Furthermore, you may assume that the original data does not contain any
// digits and that digits are only for those repeat numbers, k. For example,
// there won't be input like 3a or 2[4].
//
// Examples:
//
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> cnt;
        int num = 0;
        string res;
        for (auto c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                cnt.push(num);
                chars.push(res);
                num = 0;
                res = "";
            } else if (c == ']') {
                string temp;
                for (int i = 0; i < cnt.top(); ++i) {
                    temp += res;
                }

                cnt.pop();
                res = chars.top() + temp;
                chars.pop();
            }
        }

        return res;
    }
};

class Solution2 {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(string s, int& i) {
        int num = 0;
        string res;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i++] - '0';
            } else if (isalpha(s[i])) {
                res += s[i++];
            } else if (s[i] == '[') {
                i++;
                string temp = decodeString(s, i);
                for (int k = 0; k < num; ++k) {
                    res += temp;
                }
                num = 0;
                i++;
            } else if (s[i] == ']') {
                return res;
            }
        }
        return res;
    }
};

int main() {
    string test = "3[a2[c]]";
    Solution s;
    string res = s.decodeString(test);
    cout << res << endl;

    return 0;
}
