#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int i=0, start=0;
        while(i<nums.size()){
            if(nums[start] != nums[i]){
                nums[++start] = nums[i];
            }
            i++;
        }
        
        return start+1;
    }
};

int main(){
	vector<int> testcase={1,1,2};
	Solution s;
	int length=s.removeDuplicates(testcase);
	for(int i=0;i<length;++i){
		cout<<testcase[i]<<", ";
	}
	cout<<endl;
	return 0;
}
