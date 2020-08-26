class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if k == 0:
            return 0
        cnts = collections.defaultdict(int)
        maxLen = 0
        i = j = 0
        while j<len(s):
            cnts[s[j]] +=1
            j+=1
            while len(cnts) > k:
                cnts[s[i]] -=1
                if cnts[s[i]] == 0:
                    del cnts[s[i]]
                i+=1
            maxLen = max(maxLen, j-i)
        return maxLen
