class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> fake_bst;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int left = 0, right = fake_bst.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[i] > fake_bst[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            // not a traditional binary search tree
            // https://en.wikipedia.org/wiki/Binary_search_algorithm
            res[i] = right;
            fake_bst.insert(fake_bst.begin() + right, nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    void add(vector<int>& bit, int i) {
        while (i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }
    int sum(vector<int>& bit, int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= i & -i;
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> arr(nums), bit(nums.size() + 1, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
            arr[i] = lower_bound(nums.begin(), nums.end(), arr[i])
                     - nums.begin() + 1;
        for (int i = nums.size() - 1; i >= 0; --i) { // cout<<arr[i]<<endl;
            add(bit, arr[i]);
            arr[i] = sum(bit, arr[i] - 1);
        }
        return arr;
    }
};
