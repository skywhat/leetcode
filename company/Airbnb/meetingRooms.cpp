#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, bool> pib;

class Solution {
public:
    vector<pii> getVacant(vector<vector<pii>> meetings) {
        vector<pib> all;
        for (auto meeting : meetings) {
            for (auto i : meeting) {
                all.push_back({i.first, true});
                all.push_back({i.second, false});
            }
        }

        sort(all.begin(), all.end());

        vector<pii> res;
        int start = 0;
        int prev = all[0].first;
        for (auto i : all) {
            if (i.second) {
                // we are reaching a new start
                if (start == 0 && prev < i.first) {
                    res.push_back({prev, i.first});
                }
                start++;
            } else {
                // we are reaching a new end
                if (start == 1) {
                    prev = max(prev, i.first);
                }
                start--;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<pii>> meetings = {
        {{1, 3}, {6, 7}},
        {{2, 4}},
        {{2, 5}, {9, 12}},
    };

    Solution s;
    vector<pii> res = s.getVacant(meetings);
    for (auto r : res) {
        cout << "[" << r.first << ", " << r.second << "]" << endl;
    }

    return 0;
}
