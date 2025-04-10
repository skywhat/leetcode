class Solution:
    def compressedString(self, word: str) -> str:
        i = j = 0
        res = ""
        while j<len(word):
            while j<len(word) and word[i] == word[j] and (j-i) <9:
                j+=1
            res += str(j-i) + word[i]
            i = j
        return res