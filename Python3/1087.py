class Solution:
    def expand(self, s: str) -> List[str]:
        res = []
        self.backtracking(res, 0, "", s)
        return res
    
    def backtracking(self, res, pos, path, s):
        if pos >= len(s):
            res.append(path)
            return
        if s[pos].isalpha():
            self.backtracking(res, pos+1, path+s[pos], s)
        elif s[pos] == "{":
            j = s.find("}", pos)
            items = s[pos+1:j].split(",")
            for next_item in sorted(items):
                self.backtracking(res, j+1, path+next_item, s)


