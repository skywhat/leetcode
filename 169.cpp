#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for(auto n: nums){
            if(count == 0){
                majority = n;
                count = 1;
            }
            else if (majority == n){
                count++;
            }
            else{
                count--;
            }
        }
        
        return majority;
    }
};

class Solution2{
public:
	int majorityElement(vector<int>& nums){
		int limit=nums.size()/2;
		unordered_map<int,int> m;
		for(auto n:nums){
			if(++m[n]>limit)
				return n;
		}
        return -1;
	}
};
	
int main(){
	vector<int> nums={1,2,3,3,3,2,3};
	Solution s;
	cout<<s.majorityElement(nums)<<endl;

	return 0;
}
