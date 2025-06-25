class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) <= 10:
            return []
        sets = set()
        res = set()
        for i in range(len(s)-9):
            ss = s[i:i+10]
            if ss in sets:
                res.add(ss)
            else:
                sets.add(ss)
        return list(res)
