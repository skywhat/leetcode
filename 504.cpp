class Solution {
public:
    string convertToBase7(int num) {
        if(!num){
            return "0";
        }
        
        int temp = abs(num);
        string res;
        
        while(temp){
            res = to_string(temp%7) + res;
            temp/=7;
        }
        
        return num>0? res: "-"+res;
    }
};
