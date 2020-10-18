class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        replace = defaultdict(set)
        for s in allowed:
            replace[(s[0], s[1])].add(s[2])
        
        status = [ set([c]) for c in bottom]
        
        def generateNextStatus():
            if len(status) <=1:
                return
            for i in range(len(status) -1):
                t = set()
                for a in status[i]:
                    for b in status[i+1]:
                        t.update(replace[(a, b)])
                if t == set():
                    return
                status[i] = t
            status.pop()
            generateNextStatus()
        generateNextStatus()
        return len(status) == 1


class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        if len(bottom) <= 1:
            return True
        replace = defaultdict(set)
        for s in allowed:
            replace[(s[0], s[1])].add(s[2])

        def dfs(bottom):
            if len(bottom) == 1:
                return True
            for i in range(1, len(bottom)):
                key = (bottom[i-1], bottom[i])
                if key not in replace:
                    return False
            next_bottoms = []
            new_bottom(bottom, 1, [], next_bottoms)
            for b in next_bottoms:
                if dfs(b):
                    return True
            return False

        def new_bottom(bottom, pos, path, res):
            if pos >= len(bottom):
                res.append(path)
                return
            key = (bottom[pos-1], bottom[pos])
            for option in replace[key]:
                new_bottom(bottom, pos+1, path + [option], res)


        return dfs(list(bottom))
