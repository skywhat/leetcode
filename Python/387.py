class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = defaultdict(int)
        for c in s:
            d[c] +=1
        for i in range(len(s)):
            if d[s[i]] == 1:
                return i
        return -1
