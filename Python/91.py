class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0 or s[0] == "0":
            return 0
        prev1 = 1
        prev2 = 1
        cur = 0
        for i in range(1, n):
            cur = 0
            one = int(s[i])
            two = int(s[i-1:i+1])
            if one != 0:
                cur += prev1
            if two >= 10 and two <= 26:
                cur += prev2
            prev2 = prev1
            prev1 = cur
        return prev1
