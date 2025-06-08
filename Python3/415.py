class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ""
        i = len(num1)-1
        j = len(num2)-1
        carry = 0
        while i>=0 or j>=0 or carry:
            val = carry
            if i>=0:
                val += ord(num1[i]) - ord('0')
                i-=1
            if j>=0:
                val += ord(num2[j]) - ord('0')
                j-=1
            res = str(val%10) + res
            carry = val//10
        return res
