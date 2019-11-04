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
        unordered_set<int> sum_set;
        while(n!=1){
            int temp = n;
            int sum = 0;
            while(temp){
                sum += (temp%10)*(temp%10);
                temp /=10;
            }
            if(sum_set.count(sum)){
                return false;
            }
            sum_set.insert(sum);
            n=sum;
        }
        
        return true;
    }
};

int main(){
}
