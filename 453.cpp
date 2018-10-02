// Given a non-empty integer array of size n, find the minimum number of moves
// required to make all array elements equal, where a move is incrementing n - 1
// elements by 1.
//
// Example:
//
// Input:
// [1,2,3]
//
// Output:
// 3
//
// Explanation:
// Only three moves are needed (remember each move increments two elements):
//
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minNum = INT_MAX;
        for (auto n : nums) {
            sum += n;
            minNum = min(minNum, n);
        }
        return sum - minNum * nums.size();
    }
};
