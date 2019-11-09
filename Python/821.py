class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        n = len(S)
        pos = S.find(C)
        res = [0]*n
        for i in range(pos):
            res[i] = pos-i
        prev = pos
        for i in range(pos, n):
            if i<pos & pos!=-1:
                if pos-i < i-prev:
                    res[i] = pos-i
                else:
                    res[i] = i-prev
            elif pos!=-1:
                prev = pos
                pos = S.find(C, pos+1)
            else:
                res[i] = i-prev
        return res
