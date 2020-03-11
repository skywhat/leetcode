class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x >= 0 and x < 10:
            return True
        if x < 0 or x%10 == 0:
            return False
        part = 0
        while x > part:
            part = part*10 + x%10
            x /= 10
            if x/10 == part:
                return True
        return x == part

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        s = str(x)
        mid = len(s)/2
        left = s[:mid]
        if len(s)&1:
            right = s[mid+1:]
        else:
            right = s[mid:]
        if left == right[::-1]:
            return True
        return False
