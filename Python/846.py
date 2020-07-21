class Solution(object):
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        if len(hand) %W != 0:
            return False
        cnt = collections.Counter(hand)
        while cnt:
            start = min(cnt)
            for i in range(W):
                if start+i not in cnt:
                    return False
                cnt[start+i] -=1
                if cnt[start+i] == 0:
                    del cnt[start+i]
        return True
