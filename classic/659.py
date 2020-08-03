class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        cnt = collections.Counter(nums)
        tail = collections.defaultdict(int)
        
        for n in nums:
            if cnt[n] == 0:
                continue
            if tail[n] > 0:
                cnt[n] -=1
                tail[n] -=1
                tail[n+1] +=1
            elif cnt[n] and cnt[n+1] and cnt[n+2]:
                cnt[n] -=1
                cnt[n+1] -=1
                cnt[n+2] -=1
                tail[n+3] +=1
            else:
                return False
        return True
