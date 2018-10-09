#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_map<char, unordered_map<char, unordered_set<char>>> matrix;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        matrix m;
        for (auto s : allowed) {
            m[s[0]][s[1]].insert(s[2]);
        }

        vector<unordered_set<char>> status;
        for (auto b : bottom) {
            status.push_back({b});
        }

        generateNextStatus(m, status);

        return status.size() == 1;
    }

    void generateNextStatus(matrix& m, vector<unordered_set<char>>& status) {
        if (status.size() == 1) {
            return;
        }

        int n = status.size();
        for (int i = 0; i < n - 1; ++i) {
            unordered_set<char> temp;
            for (auto a : status[i]) {
                for (auto b : status[i + 1]) {
                    temp.insert(m[a][b].begin(), m[a][b].end());
                }
            }
            if (temp.empty()) {
                return;
            }
            status[i] = temp;
        }

        status.pop_back();
        generateNextStatus(m, status);
    }
};

int main() {
    vector<string> allowed = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    string bottom = "AABA";
    Solution s;
    cout<<s.pyramidTransition(bottom, allowed)<<endl;

    return 0;
}
