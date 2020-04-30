class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        carry = 1
        for i in range(n-1, -1, -1):
            digits[i] += carry
            if digits[i] <10:
                return digits
            digits[i] = 0
        if carry != 0:
            return [carry]+digits
