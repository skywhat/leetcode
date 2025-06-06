class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        pairsum = sorted([weights[i]+weights[i+1] for i in range(n-1)])

        diff = 0
        for i in range(k-1):
            diff += pairsum[n-i-2] - pairsum[i]
        return diff
