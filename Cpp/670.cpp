#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        vector<int> units;
        while(num){
            units.push_back(num%10);
            num/=10;
        }
        int last=units.size()-1;
        vector<int> dp(last+1,0);
        dp[0]=0;
        for(int i=1;i<=last;++i){
            if(units[i]>units[dp[i-1]])
                dp[i]=i;
            else
                dp[i]=dp[i-1];
        }
        for(int i=last;i>=0;--i){
            if(units[dp[i]]!=units[i]){
                swap(units[dp[i]],units[i]);
                break;
            }
        }
        for(int i=last;i>=0;--i)
            num=num*10+units[i];
        return num;
    }
};

/*
 2736 => 7236
 
 2736
 1 1 3 3
 
 6 3 7 2
 0 0 2 2
 
 1993 => 9913
 
 3 9 9 1
 0 1 1 1
 
 
 */
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> units;
        while(num){
            units.push_back(num%10);
            num/=10;
        }
        int last=units.size()-1;
        int ind=0;
        int maxDigit=-1;
        for(int i=last;i>=0;--i){
            for(int j=i-1;j>=0;--j){
                if(units[j]>units[i]&&units[j]>=maxDigit){
                    maxDigit=units[j];
                    ind=j;
                }
            }
            if(maxDigit!=-1){
                units[ind]=units[i];
                units[i]=maxDigit;
                break;
            }
        }
        for(int i=last;i>=0;--i){
            num=num*10+units[i];
        }
        return num;
    }
};

int main(){
    
}

