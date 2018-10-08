#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> recommend(unordered_set<string>& mine,
                             unordered_map<string, vector<string>>& friends,
                             int k) {
        vector<pair<int, string>> candidates;
        unordered_map<string, vector<string>> diffs;

        for (auto f : friends) {
            string name = f.first;
            vector<string> cities = f.second;
            vector<string> diff;
            int degree = 0;
            for (auto city : cities) {
                if (mine.count(city)) {
                    degree++;
                } else {
                    diff.push_back(city);
                }
            }

            if (degree >= cities.size() / 2) {
                candidates.push_back({degree, name});
                diffs[name] = diff;
            }
        }

        sort(candidates.begin(), candidates.end(),
             [](pair<int, string> l, pair<int, string> r) {
                 return l.first > r.first;
             });

        vector<string> recommended_cities;
        int i = 0;
        while (k > 0 && i < candidates.size()) {
            if (k < diffs[candidates[i].second].size()) {
                for (int j = 0; j < k; ++j) {
                    recommended_cities.push_back(
                        diffs[candidates[i].second][j]);
                }
                k = 0;
            } else {
                for (int j = 0; j < diffs[candidates[i].second].size(); ++j) {
                    recommended_cities.push_back(
                        diffs[candidates[i].second][j]);
                }
                k -= diffs[candidates[i].second].size();
                i++;
            }
        }

        return recommended_cities;
    }
};

int main() {
    unordered_set<string> mine = {"A", "B", "C", "D"};

    unordered_map<string, vector<string>> friends;
    friends["boyA"] = {"A", "B", "E", "F"};                // two
    friends["boyB"] = {"A", "B", "C", "G"};                // three
    friends["boyC"] = {"A", "H", "I"};                     // one
    friends["boyD"] = {"A", "B", "C", "D", "X", "Y", "Z"}; // four

    Solution s;
    int k = 5;
    vector<string> recommended_cities = s.recommend(mine, friends, k);
    for (auto city : recommended_cities) {
        cout << city << ", ";
    }
    cout << endl;

    return 0;
}
