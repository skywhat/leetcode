// We are given two strings, A and B.
//
// A shift on A consists of taking string A and moving the leftmost character to
// the rightmost position. For example, if A = 'abcde', then it will be 'bcdea'
// after one shift on A. Return True if and only if A can become B after some
// number of shifts on A.
//
// Example 1:
// Input: A = 'abcde', B = 'cdeab'
// Output: true
//
// Example 2:
// Input: A = 'abcde', B = 'abced'
// Output: false
// Note:
//
// A and B will have length at most 100.

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

// The 'shift' operation can be regarded as a 'sliding' operation on A+A.
// For example, A = “abcde”, B = “cdeab”，A+A="abcdeabcde".
// We use a sliding window of size len(A) to 'slide' on A+A from left to
// right.Every sliding takes 1 step. At the beginning, we are in the leftmost,
// the sliding window is 'abcde'. After the first sliding, we get 'bcdea'(A
// shifts onece). After the second sliding, we get 'cdeab'(A shifts twice).
// ...
// Until to the rightmost, we get 'abcde'
// So if A can become B after serveral shifts, B must be a result we get above.
// So B must be a substring of A+A

class Solution2 {
public:
    bool rotateString(string A, string B) {
        for (int i = 0; i <= A.size(); ++i) {
            if (A.substr(i) + A.substr(0, i) == B) {
                return true;
            }
        }

        return false;
    }
};
