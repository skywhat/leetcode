#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        vector<int> waters(n);

        for (int i = 0; i < V; ++i) {
            int pos = K;

            while (pos > 0 &&
                heights[pos - 1] + waters[pos - 1] <= heights[pos] + waters[pos]) {
                pos--;
            }

            while (pos < K &&
                heights[pos] + waters[pos] == heights[pos + 1] + waters[pos + 1]) {
                pos++;
            }

            if (pos == K) {
                while (pos < n - 1 &&
                    heights[pos + 1] + waters[pos + 1] <= heights[pos] + waters[pos]) {
                    pos++;
                }
                while (pos > K &&
                    heights[pos - 1] + waters[pos - 1] == heights[pos] + waters[pos]) {
                    pos--;
                }
            }

            waters[pos]++;
        }

        int highest = 0;
        for (int i = 0; i < n; ++i) {
            highest = max(heights[i] + waters[i], highest);
        }

        for (int h = highest; h >= 1; --h) {
            for (int j = 0; j < n; ++j) {
                if (heights[j] + waters[j] < h) {
                    cout << " ";
                } else if (heights[j] < h) {
                    cout << "w";
                } else {
                    cout << "#";
                }
            }
            cout << endl;
        }

        for (int i = 0; i < n; ++i) {
            heights[i] += waters[i];
        }

        return heights;
    }
};

int main() {
    vector<vector<int>> heights = {
            {2, 1, 1, 2, 1, 2, 2},
            {3, 1, 3},
            {1, 2, 3, 4},
            {1, 1, 1, 1, 1},
            {5, 3, 5, 2, 3, 1, 5},
            {10, 1, 10},
            {10, 1, 10},
        };

    vector<int> V = {4, 5, 2, 14, 6, 5, 5};
    vector<int> K = {3, 1, 2, 3, 2, 0, 2};

    Solution s;

    for (int i = 0; i < heights.size(); ++i) {
        s.pourWater(heights[i], V[i], K[i]);
        cout << endl;
    }

    return 0;
}
