class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        m, n = 2, 3
        start = ""
        for row in board:
            for c in row:
                start += chr(ord('0')+c)
        target = "123450"
        q = deque([start])
        visited = set()
        
        step = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                state = q.popleft()
                visited.add(state)
                if state == target:
                    return step
                i = state.find('0')
                for d in [-1, 1, -3, 3]:
                    j = d+i
                    #impossible move i 2 j 3 or i 3 j 2
                    if j<0 or j>5 or (i == 2 and j == 3) or (i == 3 and j == 2):
                        continue
                    t = list(state)
                    t[i], t[j] = t[j], t[i]
                    new_state = "".join(t)
                    if new_state not in visited:
                        q.append(new_state)
            step+=1
        return -1
