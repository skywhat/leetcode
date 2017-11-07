#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1]+nums[i-1];
        
        vector<int> left(n,0);
        for(int i=k,cur=sum[k];i<n;++i){
            if(sum[i+1]-sum[i+1-k]>cur){
                cur=sum[i+1]-sum[i+1-k];
                left[i]=i+1-k;
            }
            else
                left[i]=left[i-1];
        }
        
        vector<int> right(n,0);
        for(int i=n-k,cur=sum[n]-sum[n-k];i>=0;--i){
            if(sum[i+k]-sum[i]>=cur){
                cur=sum[i+k]-sum[i];
                right[i]=i;
            }
            else
                right[i]=right[i+1];
        }
        vector<int> res(3,0);
        int max3Sum=0;
        for(int i=k;i<=n-2*k;++i){
            int cur=(sum[i+k]-sum[i])+(sum[left[i-1]+k]-sum[left[i-1]])+(sum[right[i+k]+k]-sum[right[i+k]]);
            if(cur>max3Sum){
                max3Sum=cur;
                res={left[i-1],i,right[i+k]};
            }
        }
        return res;
        
    }
};

int main(){

}
