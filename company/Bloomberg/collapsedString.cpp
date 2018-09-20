// 消消乐，给个字符串，消去连续叁个以上的字符，比如：捱币币币捱捱西西地地地地地西，
// 变成捱捱捱西西地地地地地西，变成西西地地地地西，变成西西西，变成空的。返回最终字符。

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string collapse(string s) {
        stack<char> st1;
        stack<int> st2;
        int i = 0;
        while (i < s.size()) {
            if (st1.empty()) {
                st1.push(s[i]);
                st2.push(1);
            } else if (st1.top() != s[i]) {
                if (st2.top() >= 3) {
                    st1.pop();
                    st2.pop();
                    i--;
                } else {
                    st1.push(s[i]);
                    st2.push(1);
                }
            } else if (st1.top() == s[i]) {
                int cnt = st2.top();
                st2.pop();
                st2.push(cnt + 1);
            }
            i++;
        }

        string res;
        while (!st2.empty()) {
            int cnt = st2.top();
            st2.pop();
            if (cnt < 3) {
                res = string(cnt, st1.top()) + res;
            }
            st1.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> tests = {
        "aa",
        "aaa",
        "aabbba",
        "aabbaccc",
        "aabcddeeeddcccc",
        "aaaaaaabbbbbbbcccccccccddddd",
        "aabbccddeeeddccbbbbbaa",
    };

    for (auto test : tests) {
        cout << s.collapse(test) << endl;
    }

    return 0;
}
