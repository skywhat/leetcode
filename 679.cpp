// You have 4 cards each containing a number from 1 to 9. You need to judge
// whether they could operated through *, /, +, -, (, ) to get the value of 24.
//
// Example 1:
// Input: [4, 1, 8, 7]
// Output: True
// Explanation: (8-4) * (7-1) = 24
// Example 2:
// Input: [1, 2, 1, 2]
// Output: False
// Note:
// The division operator / represents real division, not integer division. For
// example, 4 / (1 - 2/3) = 12. Every operation done is between two numbers. In
// particular, we cannot use - as a unary operator. For example, with [1, 1, 1,
// 1] as input, the expression -1 - 1 - 1 - 1 is not allowed. You cannot
// concatenate numbers together. For example, if the input is [1, 2, 1, 2], we
// cannot write this as 12 + 12.

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        while (true) {
            if (isValid(nums)) {
                return true;
            }
            if (!next_permutation(nums.begin(), nums.end())) {
                break;
            }
        }
        return false;
    }

    bool isValid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (isValid(a + b, c, d) || isValid(a - b, c, d) || isValid(a * b, c, d)
            || isValid(a / b, c, d)) {
            return true;
        }
        if (isValid(a, b + c, d) || isValid(a, b - c, d) || isValid(a, b * c, d)
            || isValid(a, b / c, d)) {
            return true;
        }
        if (isValid(a, b, c + d) || isValid(a, b, c - d) || isValid(a, b, c * d)
            || isValid(a, b, c / d)) {
            return true;
        }
        return false;
    }

    bool isValid(double a, double b, double c) {
        if (isValid(a + b, c) || isValid(a - b, c) || isValid(a * b, c)
            || b && isValid(a / b, c)) {
            return true;
        }
        if (isValid(a, b + c) || isValid(a, b - c) || isValid(a, b * c)
            || c && isValid(a, b / c)) {
            return true;
        }
        return false;
    }

    double target = 24.0;
    double eps = 0.0001;
    bool isValid(double a, double b) {
        if (abs(a + b - target) < eps) {
            return true;
        }
        if (abs(a - b - target) < eps) {
            return true;
        }
        if (abs(a * b - target) < eps) {
            return true;
        }
        if (b && abs(a / b - target) < eps) {
            return true;
        }
        return false;
    }
};
