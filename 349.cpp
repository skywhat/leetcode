#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        for(int i=0;i<nums1.size();){
            int cur=nums1[i];
            if(binarySearch(nums2,cur)){
                res.push_back(cur);
            }
            while(i<nums1.size()&&nums1[i]==cur)
                i++;
        }
        return res;
    }
    
            bool binarySearch(const vector<int>& nums,int target){
            int low=0;
            int high=nums.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target)
                    return true;
                else if(nums[mid]<target)
                    low=mid+1;
                else
                    high=mid-1;
            }
            return false;
        }
};

int main(){
	vector<int> nums1={1,2,2,1};
	vector<int> nums2={2,2};
	Solution s;
	vector<int> res=s.intersection(nums1,nums2);
	for(auto r:res)
		cout<<r<<", ";
	cout<<endl;

	return 0;
}




