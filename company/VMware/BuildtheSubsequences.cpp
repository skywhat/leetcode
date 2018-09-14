#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> buildSubsequences(string s) {
        vector<string> res;
        build(s, res, 0, "");

        return res;
    }

    void build(const string& s, vector<string>& res, int pos, string temp) {
        if (pos >= s.size()) {
            if (!temp.empty()){
                res.push_back(temp);
            }
            return;
        }

        build(s, res, pos + 1, temp);
        build(s, res, pos + 1, temp + s[pos]);
    }
};

int main() {
    Solution s;
    string test = "xyz";
    auto res = s.buildSubsequences(test);

    copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));

    return 0;
}
