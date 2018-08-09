#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time: O(m+n) Space: O(m+n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return res;
    }
};

// Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> dict;
        vector<int> res;
        for(auto n: nums1){
            dict[n]++;
        }
        
        for(auto n: nums2){
            if(--dict[n]>=0){
                res.push_back(n);
            }
        }
        
        return res;
    }
};

int main(){

	vector<int> nums1={1,2,2,1};
	vector<int> nums2={2,2};

	Solution s;
	vector<int> res=s.intersect(nums1,nums2);

	for(auto r:res)
		cout<<r<<", ";
	cout<<endl;

	return 0;
}
