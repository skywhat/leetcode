#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> gaps;
        int row = wall.size();
        if (!row) {
            return 0;
        }

        for (auto each_row : wall) {
            int width = 0;
            for (int i = 0; i < each_row.size() - 1; ++i) {
                width += each_row[i];
                gaps[width]++;
            }
        }

        int max_gap = 0;
        for (auto gap : gaps) {
            max_gap = max(max_gap, gap.second);
        }

        return row - max_gap;
    }
};

// considering if the wall has a pretty long width. we can scan from top to
// bottom. O(h) space complexity.
class Solution2 {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.size() == 0)
            return 0;
        int width = 0;
        for (auto b : wall[0])
            width += b;
        vector<int> res(wall.size(), 0);
        vector<int> index(wall.size(), 1);
        for (int i = 0; i < wall.size(); ++i) {
            res[i] = wall[i][0];
        }
        int min = res[0];
        int maxCount = 0;
        while (true) {
            int count = 0;
            for (int i = 0; i < res.size(); ++i) {
                if (res[i] < min)
                    min = res[i];
            }
            if (min == width)
                break;
            for (int i = 0; i < res.size(); ++i) {
                if (min < width && min == res[i]) {
                    count++;
                    res[i] += wall[i][index[i]++];
                }
            }
            min = res[0];
            maxCount = max(maxCount, count);
        }
        return wall.size() - maxCount;
    }
};

int main() {}
