// Input: A = [x1, x2, ..., xn]
// Sum T = Round(x1+x2+... +xn)  ;  178.93E => 179
// Output: B = [y1, y2, ...., yn]
//
// Constraint #1: y1+y2+...+yn = T
// Constraint #2: minimize sum(abs(diff(xi - yi)))
//
// for example
// A = [1.2, 2.3, 3.4]
// Round(1.2 + 2.3 + 3.4) = 6.9 => 7
// 1 + 2 + 3 => 6
//
// 1 + 3 + 3 => 7
// 0.2 + 0.7 + 0.4 = 1.3
//
// 1 + 2 + 4 => 7
// 0.2 + 0.3 + 0.6 = 1.1
// so [1,2,4] is better than [1,3,3]

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Complete the roundPricesToMatchTarget function below.
vector<int> roundPricesToMatchTarget(vector<float> prices, int target) {
    int n = prices.size();
    int floor_sum = 0;

    vector<pair<int, float>> diffs(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        int floor_val = floor(prices[i]);
        floor_sum += floor_val;
        if (floor(prices[i]) == prices[i]) {
            diffs[i] = {i, 1};
        } else {
            diffs[i] = {i, ceil(prices[i]) - prices[i]};
        }
    }

    sort(diffs.begin(), diffs.end(),
         [](pair<int, float> l, pair<int, float> r) {
             return l.second < r.second;
         });

    int cost = target - floor_sum;
    vector<int> res(n);
    // restore result from diffs array based on diffs[i].first
    int i = 0;
    for (; i < cost; ++i) {
        res[diffs[i].first] = floor(prices[diffs[i].first]) + 1;
    }
    for (; i < n; ++i) {
        res[diffs[i].first] = floor(prices[diffs[i].first]);
    }

    return res;
}

int main() {
    vector<vector<float>> tests = {
        {1.0, 2.0, 3.5}, // 1 2 4
        {0.7, 2.8, 4.9}, // 0 3 5
        {1.2, 2.3, 3.4}, // 1 2 4
        {1.0, 2.0, 3.0}  // 1 2 3
    };

    vector<int> targets = {
        7,
        8,
        7,
        6,
    };

    for (int i=0;i<tests.size();++i) {
        auto res = roundPricesToMatchTarget(tests[i], targets[i]);
        for (auto r : res) {
            cout << r << ", ";
        }
        cout << endl;
    }

    return 0;
}
