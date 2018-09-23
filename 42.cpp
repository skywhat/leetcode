#include <iostream>
#include <vector>

using namespace std;

/*

 Here is my idea: instead of calculating area by height*width, we can think it
 in a cumulative way. In other words, sum water amount of each bin(width=1).
 Search from left to right and maintain a max height of left and right
 separately, which is like a one-side wall of partial container. Fix the higher
 one and flow water from the lower part. For example, if current height of left
 is lower, we fill water in the left bin. Until left meets right, we filled the
 whole container.

 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        int i = 0, j = height.size() - 1;
        int left = height[i];
        int right = height[j];
        int res = 0;

        while (i < j) {
            if (left <= right) {
                res += left - height[i];
                i++;
                left = max(left, height[i]);
            } else {
                res += right - height[j];
                j--;
                right = max(right, height[j]);
            }
        }

        return res;
    }
};

int main() {}
