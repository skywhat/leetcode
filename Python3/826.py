class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        res = 0
        i = 0
        max_profit = 0
        for worker_cap in sorted(worker):
            while i<len(jobs) and jobs[i][0] <= worker_cap:
                max_profit = max(jobs[i][1], max_profit)
                i+=1
            res += max_profit
        return res
