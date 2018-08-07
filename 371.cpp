class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while(b!=0){
            sum = a^b;// calculate sum of a a and b without thinking the carry
            b = (a&b)<<1;// calculate the carry  
            a = sum;// add sum(without carry) and carry
        }
        return sum;
    }
};
