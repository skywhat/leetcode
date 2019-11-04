// You have k lists of sorted integers in ascending order. Find the smallest
// range that includes at least one number from each of the k lists.
//
// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
// if b-a == d-c.
//
// Example 1:
// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation:
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Note:
// The given list may contain duplicates, so ascending order means >= here.
// 1 <= k <= 3500
// -105 <= value of elements <= 105.
// For Java users, please note that the input type has been changed to
// List<List<Integer>>. And after you reset the code template, you'll see this
// point.

class Solution {
public:
    typedef vector<int>::iterator vi;
    typedef pair<vi, vi> pii;
    struct comp {
        bool operator()(pii l, pii r) { return *l.first > *r.first; }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pii, vector<pii>, comp> q;
        int lo = INT_MAX;
        int hi = INT_MIN;

        for (auto& n : nums) {
            q.push({n.begin(), n.end()});
            lo = min(lo, n[0]);
            hi = max(hi, n[0]);
        }

        vector<int> res = {lo, hi};
        while (true) {
            auto temp = q.top();
            q.pop();
            temp.first++;
            if (temp.first == temp.second) {
                break;
            }
            q.push(temp);
            lo = *q.top().first;
            hi = max(hi, *temp.first);
            if (hi - lo < res[1] - res[0]) {
                res = {lo, hi};
            }
        }

        return res;
    }
};
