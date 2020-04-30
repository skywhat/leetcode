class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = dict()
        for s in strs:
            key = tuple(sorted(s))
            d[key] = d.get(key,[])+[s]
        return d.values()
