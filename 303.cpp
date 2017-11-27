#include<iostream>
#include<vector>

using namespace std;

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        int n=nums.size();
        sum.assign(n+1,0);
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1]+nums[i-1];
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
