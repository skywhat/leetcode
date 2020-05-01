class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        l = [x for x in path.split('/') if x !="" and x!="."]
        res = []
        for x in l:
            if x == "..":
                if res:
                    res.pop()
            else:
                res.append(x)
        return "/"+"/".join(res)
