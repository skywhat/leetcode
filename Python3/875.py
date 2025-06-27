class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if h == len(piles):
            return max(piles)
        
        def hourNeeded(piles, k):
            hour = 0
            for p in piles:
                hour += p//k
                if p%k !=0:
                    hour +=1
            return hour
        
        i, j = 1, max(piles)
        while i+1 < j:
            mid = (i+j)//2
            hour = hourNeeded(piles, mid)
            if hour <= h:
                j = mid
            else:
                i = mid
        # i+1==j or i==j
        hour = hourNeeded(piles, i)
        if hour <= h:
            return i
        return j
        
