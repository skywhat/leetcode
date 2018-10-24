// There are N workers.  The i-th worker has a quality[i] and a minimum wage
// expectation wage[i].
//
// Now we want to hire exactly K workers to form a paid group.  When hiring a
// group of K workers, we must pay them according to the following rules:
//
// Every worker in the paid group should be paid in the ratio of their quality
// compared to other workers in the paid group. Every worker in the paid group
// must be paid at least their minimum wage expectation. Return the least amount
// of money needed to form a paid group satisfying the above conditions.
//
//
//
// Example 1:
//
// Input: quality = [10,20,5], wage = [70,50,30], K = 2
// Output: 105.00000
// Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
// Example 2:
//
// Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
// Output: 30.66667
// Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers
// seperately.
//
//
// Note:
//
// 1 <= K <= N <= 10000, where N = quality.length = wage.length
// 1 <= quality[i] <= 10000
// 1 <= wage[i] <= 10000
// Answers within 10^-5 of the correct answer will be considered correct.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality,
                                vector<int>& wage,
                                int K) {
        vector<vector<double>> ratio_and_q;
        for (int i = 0; i < quality.size(); ++i) {
            ratio_and_q.push_back({wage[i] / double(quality[i]), quality[i]});
        }

        double res = INT_MAX;
        double qsum = 0;
        priority_queue<double> q;
        sort(ratio_and_q.begin(), ratio_and_q.end());

        for (int i = 0; i < ratio_and_q.size(); ++i) {
            qsum += ratio_and_q[i][1];
            q.push(ratio_and_q[i][1]);
            if (q.size() > K) {
                qsum -= q.top();
                q.pop();
            }
            if (q.size() == K) {
                res = min(res, qsum * ratio_and_q[i][0]);
            }
        }

        return res;
    }
};
