#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        for(int i=1;i<n;++i){
            res[i]=res[i-1]*nums[i-1];
        }
        int tmp=nums[n-1];
        for(int i=n-2;i>=0;--i){
            res[i]*=tmp;
            tmp*=nums[i];
        }
        return res;
    }
};

/*
1 2 3 4
1 1 1 1
1 1 2 6

tmp=4
1 1 2 6
1 1 8 6
tmp=4*3=12
1 12 8 6

tmp=4*3*2=24
24 12 8 6


*/

int main(){

}


