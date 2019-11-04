// Given an array of integers A, find the sum of min(B), where B ranges over
// every (contiguous) subarray of A.
//
// Since the answer may be large, return the answer modulo 10^9 + 7.
//
//
//
// Example 1:
//
// Input: [3,1,2,4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
// [1,2,4], [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
//
//
// Note:
//
// 1 <= A.length <= 30000
// 1 <= A[i] <= 30000

class Solution {
public:
    const int P = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        stack<int> st;
        int n = A.size();
        vector<int> left(n, -1), right(n, n);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && A[st.top()] > A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (i - left[i]) * (right[i] - i) * A[i]) % P;
        }

        return sum;
    }
};
