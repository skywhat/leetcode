class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or len(s) <= numRows:
            return s
        res = ['']*numRows
        ind, step = 0, 1
        for i in range(len(s)):
            res[ind] += s[i]
            ind += step
            if ind == 0 or ind == numRows-1:
                step = -step
        return ''.join(res)
           

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        res = ""
        gap = 2*numRows-2
        for i in range(numRows):
            start = i
            step = 2*(numRows-i)-2
            while start <len(s):
                if step !=0:
                    res += s[start]
                start += step
                step = gap-step
        return res

