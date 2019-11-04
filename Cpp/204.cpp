// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                res++;
            }
            for (int j = 2; j * i < n; ++j) {
                is_prime[j * i] = false;
            }
        }

        return res;
    }
};
