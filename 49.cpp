#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }

        vector<vector<string>> res(m.size());
        int row = 0;
        for (auto item : m) {
            for (auto i : item.second) {
                res[row].push_back(strs[i]);
            }
            row++;
        }

        return res;
    }
};

int main() {
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(test);

    for (auto i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
