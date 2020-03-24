class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        res = strs[0]
        for i in range(1, len(strs)):
            res = self.commonPrefix(res, strs[i])
        return res
            
    def commonPrefix(self, s1, s2):
        for i in range(len(s1)):
            if s1[:i+1] != s2[:i+1]:
                return s1[:i]
        return s1
            


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        for i in range(len(strs[0])):
            for k in range(1, len(strs)):
                if i >= len(strs[k]) or strs[0][i] != strs[k][i]:
                    return strs[0][:i]
        return strs[0]
            
