class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        s = []
        j = 0
        for x in pushed:
            s.append(x)
            while j< len(popped) and s and s[-1] == popped[j]:
                s.pop()
                j+=1
        return j==len(popped)
