class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = -1
        pos = {}
        maxLen = 0
        for i in range(len(s)):
            if (s[i] not in pos) or (pos[s[i]] <= start):
                maxLen = max(maxLen, i-start)
            else:
                start = pos[s[i]]
            pos[s[i]] = i
        return maxLen
                
'''
a b c a b c b b
0 1 2 3 4 5 6 7

i=0
start = -1
maxLen = 1
pos{'a':0, }

i=1
start = -1
maxLen = 2
pos{'a':0, 'b':1}

i=2
start = -1
maxLen = 3
pos{'a':0, 'b':1, 'c':2}

i = 3
start = 2
pos{'a':3. 'b':1, 'c':2}


"t m m z u x t"
 0 1 2 3 4 5 6

start = -1
i=0
maxLen = 1
pos{'t':0}

i=1
maxLen = 2
pos{'t':0, 'm':1}

i=2
start = 1
pos{'t':0, 'm':2}

i=3
maxLen = 2
pos{'t':0, 'm':2, 'z':3}

i=4
maxLen = 3
pos{'t':0, 'm':2, 'z':3, 'u':4}

i=5
maxLen = 4
pos{'t':0, 'm':2, 'z':3, 'u':4, 'x':5}

i=6
maxLen = 5
pos{'t':6, 'm':2, 'z':3, 'u':4, 'x':5}

'''
