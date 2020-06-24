class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        if k >= len(num):
            return "0"
        stk = []
        for i in range(len(num)):
            while stk and k>0 and stk[-1] > num[i]:
                stk.pop()
                k-=1
            stk.append(num[i])
        num =  "".join(stk)
        if k != 0:
            num = num[:-k]
        return str(int(num))
