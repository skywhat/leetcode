class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 = 3^19 max power of three 
        return n>0 && 1162261467%n == 0;
    }
};
