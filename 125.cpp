#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
private:
        vector<int> alpha_numeric;
public:
    Solution(){
        alpha_numeric.assign(128, 0);
        for(int i='a';i<='z';++i){
            alpha_numeric[i] = i;
        }
        for(int i='A';i<='Z';++i){
            alpha_numeric[i] = i-'A'+'a';
        }
        for(int i='0';i<='9';++i){
            alpha_numeric[i] = i;
        }
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(alpha_numeric[s[i]] == 0){
                i++;
                continue;
            }
            if(alpha_numeric[s[j]] == 0){
                j--;
                continue;
            }
            if(alpha_numeric[s[i++]] != alpha_numeric[s[j--]]){
                return false;
            }
        }
        
        return true;
    }
};

int main(){

}
