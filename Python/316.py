class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        seen = set()
        last_occurrence = {}
        for i, x in enumerate(s):
            last_occurrence[x] = i
        for i in range(len(s)):
            if s[i] not in seen:
                while stack and s[i] < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.discard(stack.pop())
                stack.append(s[i])
                seen.add(s[i])
        return "".join(stack)


class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        counts = collections.Counter(s)
        pos = 0
        for i, x in enumerate(s):
            if x < s[pos]:
                pos = i
            counts[s[i]] -=1
            if counts[s[i]] == 0:
                break
        return s[pos] + self.removeDuplicateLetters(s[pos+1:].replace(s[pos], ""))
