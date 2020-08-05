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


#https://www.zhihu.com/question/37289584
#Manacher Algorithm
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = "^#" + "#".join(s) + "#$"
        C = R = 0
        n = len(t)
        p = [0]*n

        for i in range(1, n-1):
            i_mirror = 2*C-i
            if i<R:
                p[i] = min(p[i_mirror], R-i)
            else:
                p[i] = 0

            while t[i-1-p[i]] == t[i+1+p[i]]:
                p[i]+=1

            if i+p[i] > R:
                R = i+p[i]
                C = i
        maxLen = 0
        start = 0
        for i, x in enumerate(p):
            if x > maxLen:
                maxLen = x
                start = i
        start = (start - maxLen)/2
        return s[start:start+maxLen]

