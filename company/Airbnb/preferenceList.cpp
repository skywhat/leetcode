#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getPreferenceList(vector<vector<int>>& list) {
        map<int, set<int>> suc, prev;
        set<int> all;
        for (auto l : list) {
            all.insert(l.begin(), l.end());
            for (int i = 1; i < l.size(); ++i) {
                suc[l[i - 1]].insert(l[i]);
                prev[l[i]].insert(l[i - 1]);
            }
        }

        for (auto p : prev) {
            all.erase(p.first);
        }

        vector<int> res;
        while (!all.empty()) {
            char cur = *all.begin();
            all.erase(all.begin());
            res.push_back(cur);

            for (auto next : suc[cur]) {
                prev[next].erase(cur);
                if (prev[next].empty()) {
                    all.insert(next);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<vector<int>> list = {{2, 3, 5}, {4, 2, 1}, {4, 1, 5, 6}, {4, 7}};
    vector<int> result = s.getPreferenceList(list);
    for (auto it : result)
        cout << it << " ";
    return 0;
}
