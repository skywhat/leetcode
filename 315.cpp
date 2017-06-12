class Solution{
	public:
		vector<int> countSmaller(vector<int>& nums){
			vector<int> res(nums.size(),0);
			vector<int> fake_bst;
			for(int i=nums.size()-1;i>=0;i--){
				int left=0,right=fake_bst.size();
				while(left<right){
					int mid=(left+right)/2;
					if(nums[mid]>fake_bst[mid])
						left=mid+1;
					else
						right=mid;
				}
				//not a traditional binary search tree
				//https://en.wikipedia.org/wiki/Binary_search_algorithm
				nums[i]=right;
				fake_bst.insert(fake_bst.begin()+right,nums[i]);
			}
			return res;
		}
};
