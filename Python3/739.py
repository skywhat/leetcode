class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s = [] # idx
        n = len(temperatures)
        res = [0]*n
        for i, t in enumerate(temperatures):
            while s and temperatures[s[-1]] < t:
                idx = s.pop()
                res[idx] = i-idx
            s.append(i)
        return res
