/*
Given n non-negative integers representing the histogram's bar height where the
width of each bar is 1, find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].





The largest rectangle is shown in the shaded area, which has area = 10 unit.



For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// O(n^3) Time Limit Exceeded
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j < heights.size(); ++j) {
                int height = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    height = min(height, heights[k]);
                }
                max_area = max(max_area, (j - i + 1) * height);
            }
        }

        return max_area;
    }
};

// O(n^2)
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            int left = i, right = i;
            while (left >= 0 && heights[left] >= heights[i]) {
                left--;
            }
            while (right < heights.size() && heights[right] >= heights[i]) {
                right++;
            }
            max_area = max(max_area, (right - left - 1) * heights[i]);
        }

        return max_area;
    }
};
/*
The key point is recording the index of histogram bars in non-descending order.
Only when we find the minmum height, the stack will be empty.
*/
class Solution3 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        // we need the index of end over the last period of non-descending order
        heights.push_back(0);
        int max_area = 0;

        int i = 0;
        while (i < heights.size()) {
            if (index.empty() || heights[index.top()] <= heights[i]) {
                index.push(i);
                i++;
            } else {
                int h = heights[index.top()];
                index.pop();
                int left_index = index.empty() ? -1 : index.top();
                max_area = max(max_area, (i - left_index - 1) * h);
            }
        }

        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> h = {4, 2, 0, 3, 2, 5};
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}
