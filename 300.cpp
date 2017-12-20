#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> length(nums.size(),1);
		int maxLength = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i] && length[i] < length[j] + 1)
					length[i]=length[j]+1;
			}
			maxLength = max(maxLength,length[i]);
		}
		return maxLength;
	}
};
//19ms O(n^2)


class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> tail(nums.size(),0);
        tail[0]=nums[0];
        int len=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<tail[0])
                tail[0]=nums[i];
            else if(nums[i]>tail[len-1])
                tail[len++]=nums[i];
            else
                tail[find(tail,len,nums[i])]=nums[i];
        }
        return len;
    }
    int find(vector<int>& tail,int len,int target){
        int i=0,j=len-1;
        while(i+1<j){
            int mid=i+(j-i)/2;
            if(tail[mid]>target)
                j=mid;
            else
                i=mid;
        }
        if(tail[i]<target)
            return j;
        return i;
    }
};
//3ms O(nlgn)
//
