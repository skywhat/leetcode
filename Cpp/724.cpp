class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        if(n<3){
            return -1;
        }
        
        vector<int> sum(n+1, 0);
        for(int i=1;i<=n;++i){
            sum[i] = sum[i-1] + nums[i-1];
        }
        for(int i=1;i<=n;++i){
            if(sum[i-1] == sum[n]-sum[i]){
                return i-1;
            }
        }
        
        return -1;
    }
};


/*
 * edge case:
 * Input: [-1,-1,-1,0,1,1]
 * Expected: 0
 * */
