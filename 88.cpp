#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0;
		while (i < m&&j < n) {
			if (nums1[i] < nums2[j])
				i++;
			else {
				nums1.insert(nums1.begin() + i, nums2[j++]);
				m++;
				i++;
			}
		}
		for (; j < n; ++j,++m)
			nums1.insert(nums1.begin()+m, nums2[j]);
		nums1.erase(nums1.begin()+m,nums1.end());
	}
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};

int main() {
	vector<int> nums1 = { 0 };
	int m = 0;
	vector<int> nums2 = {1};
	int n = 1;
	Solution s;
	s.merge(nums1,m,nums2,n);
	copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, ", "));

	return 0;

}
