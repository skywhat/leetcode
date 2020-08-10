class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        s = []
        res = [0]*len(T)
        for i, t in enumerate(T):
            while s and s[-1][0] < t:
                _, ind = s.pop()
                res[ind] = i-ind
            s.append((t, i))
        return res
                


class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        tpos = [float('inf')]*102
        res = [0]*len(T)
        for i in range(len(T)-1, -1, -1):
            warmer = min([tpos[x] for x in range(T[i]+1, 102)])
            if warmer != float('inf'):
                res[i] = warmer -i
            tpos[T[i]] = i
        return res
