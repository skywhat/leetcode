#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> help(nums);
        sort(help.begin(),help.end());
        for(int i=0,k=(n-1)/2,l=n-1;i<n;++i){
            nums[i]=help[i&1?l--:k--];
        }
    }
};
/*

odd:
0 1 2 3 4 5 6
6 5 4
3 2 1 0

3 6 2 5 1 4 0

even:
0 1 2 3 4 5 6 7
7 6 5 4
3 2 1 0

3 7 2 6 1 5 0 4


*/
