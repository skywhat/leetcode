class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        res = []
        in_block = False
        for line in source:
            if not in_block:
                new_line = []
            i = 0
            while i<len(line):
                if not in_block and line[i:i+2] == "/*":
                    in_block = True
                    i+=1
                elif in_block and line[i:i+2] == "*/":
                    in_block = False
                    i+=1
                elif not in_block and line[i:i+2] == "//":
                    break
                elif not in_block:
                    new_line.append(line[i])
                i+=1
            if new_line and not in_block:
                res.append("".join(new_line))
        return res
