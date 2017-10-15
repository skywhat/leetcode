#include<iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow=n,fast=squareSum(n);
        while(slow!=fast){
            slow=squareSum(slow);
            fast=squareSum(squareSum(fast));
        }
        return slow==1?true:false;
    }
    int squareSum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
};

class Solution2 {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true){
            int sum=0;
            while(n){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            if(sum==1)
                return true;
            if(s.find(sum)!=s.end())
                return false;
            s.insert(sum);
            n=sum;
        }
    }
};

int main(){
}
