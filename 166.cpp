// Given two integers representing the numerator and denominator of a fraction,
// return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in
// parentheses.
//
// Example 1:
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:
//
// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if (numerator == 0) {
            return "0";
        }

        if (numerator < 0 ^ denominator < 0) {
            res += "-";
        }

        int64_t n = abs((int64_t)numerator);
        int64_t d = abs((int64_t)denominator);

        res += to_string(n / d);
        if (n % d == 0) {
            return res;
        }
        res += ".";

        unordered_map<int, int> m;
        for (int64_t i = n % d; i; i = i % d) {
            if (m.count(i)) {
                res.insert(m[i], 1, '(');
                res += ')';
                break;
            }
            m[i] = res.size();
            i *= 10;
            res += to_string(i / d);
        }

        return res;
    }
};

class Solution2 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string res;
        if (numerator < 0 ^ denominator < 0) {
            res += "-";
        }
        long n = abs(long(numerator));
        long d = abs(long(denominator));

        res += to_string(n / d);
        if (n % d == 0) {
            return res;
        }

        res += ".";
        unordered_map<int, int> m;
        n %= d;
        while (n) {
            if (m.count(n)) {
                res.insert(m[n], 1, '(');
                res += ")";
                break;
            }
            m[n] = res.size();
            n *= 10;
            res += to_string(n / d);
            n %= d;
        }

        return res;
    }
};
