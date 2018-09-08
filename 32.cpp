// Given a string containing just the characters '(' and ')', find the length of
// the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        int longest = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                    longest = max(longest, dp[i]);
                } else {
                    int prev = i - dp[i - 1];
                    if (prev - 1 >= 0 && s[prev - 1] == '(') {
                        dp[i] = dp[i - 1] + 2
                                + (prev - 2 >= 0 ? dp[prev - 2] : 0);
                        longest = max(longest, dp[i]);
                    }
                }
            }
        }

        return longest;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')' && !st.empty() && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
            // if (s[i] == ')') {
            //     if (!st.empty()) {
            //         if (s[st.top()] == '(') {
            //             st.pop();
            //         } else {
            //             st.push(i);
            //         }
            //     } else {
            //         st.push(i);
            //     }
            // } else {
            //     st.push(i);
            // }
        }

        if (st.empty()) {
            return n;
        }

        int longest = 0;
        int left = 0, right = n;
        while (!st.empty()) {
            left = st.top();
            st.pop();
            longest = max(longest, right - left - 1);
            right = left;
        }
        longest = max(longest, right);

        return longest;
    }
};
