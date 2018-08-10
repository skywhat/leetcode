class Solution {
private:
    const string HEX = "0123456789abcdef";
public:
    string toHex(int num) {
        if(!num){
            return "0";
        }
        
        string res;
        unsigned n = num;
        while(n){
            int digit = n&0xf;
            res = HEX[digit] + res;
            n>>=4;
        }
        
        return res;
    }
};
