/*
input int[],
Print out all unique indexes that satisfies nums[A] + nums[B] = nums[C] +
nums[D] Duplicate: (A,B) == (B,A), (C,D) == (D,C) (A,B,C,D) == (C,D,A,B) ==
(B,A,C,D)==(C,D,B,A)==(D,C,A,B)==(D,C,B,A)..... Example: [10,20,0,10,20] 0  1  2
3 4 print:     0,1,3,4 0,2,2,3 1,2,2,4
           ...

Example: [0,0,0,0,0]
print:    0,1,1,2
          0,1,0,2
          ....
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> equalPair(vector<int>& nums) {
        vector<vector<int>> res;
        for (int a = 0; a < nums.size() - 1; ++a) {
            for (int b = a + 1; b < nums.size(); ++b) {
                int sum = nums[a] + nums[b];
                for (int c = 0; c < nums.size() - 1; ++c) {
                    for (int d = c + 1; d < nums.size(); ++d) {
                        // if(((c>a&&d>=b)||(c<=a&&d>b))&&nums[c]+nums[d]==sum){
                        if ((b < d || (b == d && a < c))
                            && nums[c] + nums[d] == sum) {
                            res.push_back({a, b, c, d});
                        }
                        /* abviously, a<b and c<d
                         * since a+b=c+d is same as c+d=a+b
                         * we can always put the larger index into d, then b<d
                         * if a number is reused, b=d
                         * we need the condition a<c
                         */
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> equalPair(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> m;
        for (int a = 0; a < nums.size() - 1; ++a) {
            for (int b = a + 1; b < nums.size(); ++b) {
                m[nums[a] + nums[b]].push_back({a, b});
            }
        }
        for (auto&& it : m) {
            for (int i = 0; i < it.second.size() - 1; ++i) {
                for (int j = i + 1; j < it.second.size(); ++j) {
                    res.push_back({it.second[i].first, it.second[i].second,
                                   it.second[j].first, it.second[j].second});
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 0};
    vector<int> nums3 = {3, 4, 7, 1, 2, 9, 8};
    Solution2 s;
    auto res = s.equalPair(nums2);
    cout << "total pairs: " << res.size() << endl;
    for (auto&& row : res) {
        cout << "[";
        for (auto&& n : row) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
