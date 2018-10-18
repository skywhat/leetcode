#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define eps 0.001

class Solution {
public:
    vector<vector<double>> getCombinationPrices(vector<double> prices,
                                                double target) {
        vector<vector<double>> res;
        combine(prices, vector<double>(), target, 0, res);
        return res;
    }

    void combine(vector<double>& prices,
                 vector<double> temp,
                 double target,
                 int pos,
                 vector<vector<double>>& res) {
        if (target < -eps || pos >= prices.size()) {
            return;
        }

        if (target < abs(eps)) {
            res.push_back(temp);
            return;
        }

        for (int i = pos; i < prices.size(); ++i) {
            temp.push_back(prices[i]);
            combine(prices, temp, target - prices[i], i, res);
            temp.pop_back();
        }
    }
};

int main() {
    Solution s;

    vector<double> prices = {1.22, 3.66, 4.00, 3.22, 2.00};
    auto res = s.getCombinationPrices(prices, 8.88);
    for (auto ret : res) {
        for (auto str : ret) {
            cout << str << ", ";
        }
        cout << endl;
    }
    return 0;
}
