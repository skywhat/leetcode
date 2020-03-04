class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        start = end = 0
        for i in range(len(s)):
            left, right = self.expandFromCenter(s, i, i)
            if right - left > end - start:
                start = left
                end = right
            left, right = self.expandFromCenter(s, i, i+1)
            if right - left > end - start:
                start = left
                end = right
        return s[start:end+1]
        
    def expandFromCenter(self, s, left, right):
        while left >=0 and right < len(s) and s[left] == s[right]:
            left -=1
            right +=1
        return left+1, right-1
