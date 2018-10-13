// 给每个user访问历史记录，找出两个user之间longest continuous common history
// 输入： [
//              ["3234.html", "xys.html", "7hsaa.html"], // user1
//              ["3234.html", ''sdhsfjdsh.html", "xys.html", "7hsaa.html"] //
//              user2
//            ], user1 and user2 （指定两个user求intersect）
//
// 输出：["xys.html", "7hsaa.html"]-google 1po


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findLCCH(vector<string> s1, vector<string> s2) {
        int m = s1.size();
        int n = s2.size();
        int max_len = 0;
        int end = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end = i - 1;
                }
            }
        }

        vector<string> res;
        for (int k = end - max_len + 1; k <= end; ++k) {
            res.push_back(s1[k]);
        }

        return res;
    }
};

int main() {
    vector<string> user0
        = {"/nine.html", "/four.html", "/six.html", "/seven.html", "/one.html"};
    vector<string> user2 = {"/nine.html", "/two.html", "/three.html",
                            "/four.html", "/six.html", "/seven.html"};
    vector<string> user1
        = {"/one.html", "/two.html", "/three.html", "/four.html", "/six.html"};
    vector<string> user3 = {"/three.html", "/eight.html"};

    Solution s;
    vector<string> res = s.findLCCH(user0, user2);
    for (auto str : res) {
        cout << str << ", ";
    }
    cout << endl;

    return 0;
}
