class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = dict()
        for i in range(26):
	        m[chr(ord('A')+i)] = i+1
        res = 0
        for i in range(len(s)):
            res = 26*res + m[s[i]]
        return res


class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = dict()
        for i in range(26):
	        m[chr(ord('A')+i)] = i+1
        res = 0
        for i in range(len(s)):
	        res += m[s[i]]*26**(len(s)-i-1)
        return res
