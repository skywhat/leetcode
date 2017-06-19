/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].





The largest rectangle is shown in the shaded area, which has area = 10 unit.



For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*
The key point is recording the index of histogram bars in non-descending order.
Only when we find the minmum height, the stack will be empty.
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		//we need the index of end over the last period of non-descending order
		stack<int> s;
		int maxArea = 0;
		int Area;
		int width;
		for (int i = 0; i < heights.size(); ) {
			if(s.empty() || heights[i] > heights[s.top()]) {
				s.push(i);
				i++;
			}
			else {
				int index = s.top();
				s.pop();
				if (s.empty())
					width = i;
				//the bar which has the minumu height.
				else
					width = i -s.top() - 1;
				//the left index is s.top()
				Area = heights[index] * width;
				if (Area > maxArea)
					maxArea = Area;
			}
		}
		return maxArea;
	}
};

int main() {
	Solution s;
	vector<int> h = {4,2,0,3,2,5};
	cout << s.largestRectangleArea(h) << endl;
	return 0;
}