// Given two strings A and B of lowercase letters, return true if and only if we
// can swap two letters in A so that the result equals B.
//
//
//
// Example 1:
//
// Input: A = "ab", B = "ba"
// Output: true
// Example 2:
//
// Input: A = "ab", B = "ab"
// Output: false
// Example 3:
//
// Input: A = "aa", B = "aa"
// Output: true
// Example 4:
//
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:
//
// Input: A = "", B = "aa"
// Output: false
//
//
// Note:
//
// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }

        if(A == B){
            set<char> s(A.begin(), A.end());
            return s.size() < A.size();
        }

        int x, y;
        int cnt = 0;
        for(int i=0; i<A.size(); ++i){
            if(A[i] != B[i]){
                x = y;
                y = i;
                cnt++;
            }
        }

        if(cnt == 2){
            swap(A[x], A[y]);
            return A == B;
        }

        return false;
    }
};
