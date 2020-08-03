class Solution(object):
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if n == 1:
            return "".join([str(i) for i in range(k)])
        def dfs(pswd ,visited, total):
            if len(visited) == total:
                return pswd
            for i in range(k):
                next = pswd[-(n-1):] + str(i)
                if next not in visited:
                    visited.add(next)
                    res = dfs(pswd+str(i), visited, total)
                    if res:
                        return res
                    visited.remove(next)
        
        return dfs("0"*n, set(["0"*n]), k**n)
        
