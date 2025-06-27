class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        d = defaultdict(int)
        for x, y in flowers:
            d[x] +=1
            d[y+1] -=1
        keys = sorted(d.keys())
        res = []
        presum = []
        total = 0
        for key in keys:
            total += d[key]
            presum.append(total)
        for t in people:
            idx = self.findIdx(keys, t)
            val = presum[idx] if idx>=0 else 0
            res.append(val)

        return res

    def findIdx(self, keys, target):
        if target < keys[0]:
            return -1
        i, j = 0, len(keys)-1
        while i+1<j:
            mid = (i+j)//2
            if keys[mid] <= target:
                i = mid
            else:
                j = mid
        # i+1 == j or i== j
        if keys[j] <= target:
            return j
        return i


class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        start = []
        end = []
        for x, y in flowers:
            start.append(x)
            end.append(y)
        start = sorted(start)
        end = sorted(end)
        res = []
        for idx in people:
            start_idx = self.findStartIdx(start, idx)
            end_idx = self.findEndIdx(end, idx)
            res.append(start_idx - end_idx)
        return res

    def findEndIdx(self, times, target):
        if times[0] >= target:
            return -1
        i, j = 0, len(times)-1
        while i+1 < j:
            mid = (i+j)//2
            if times[mid] < target:
                i = mid
            else:
                j = mid
        # i+1 == j or i == j
        if times[j] < target:
            return j
        return i

    def findStartIdx(self, times, target):
        if times[0] > target:
            return -1
        i, j = 0, len(times)-1
        while i+1 < j:
            mid = (i+j)//2
            if times[mid] <= target:
                i = mid
            else:
                j = mid
        # i+1 == j or i == j
        if times[j] <= target:
            return j
        return i
