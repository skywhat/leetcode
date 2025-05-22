class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if len(piles) == h:
            return max(piles)
        l, r = 1, max(piles)

        def hoursNeeded(k):
            cnt = 0
            for p in piles:
                cnt += p//k
                if p%k != 0:
                    cnt +=1
            return cnt
        
        while l<r:
            mid = (l+r)//2
            needed = hoursNeeded(mid)
            # print("needed", needed, "mid", mid)
            # even needed == h, we want to try smaller one.
            if needed <= h:
                r = mid
            else:
                l = mid+1
        return l


