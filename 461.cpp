#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y;
        int sum=0;
        for(int i=0;i<=31;++i){
            if(temp&1)
            sum++;
            temp>>=1;
        }
        return sum;
    }
};

int main(){
    
}
