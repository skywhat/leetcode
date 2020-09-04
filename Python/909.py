class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        N = len(board)
        def get(s):
            q, r = divmod(s-1, N)
            row = N-1-q
            col = r if N%2 != row%2 else N-1-r
            return row, col
        
        dist = {1:0}
        q = deque([1])
        while q:
            # print q
            # print dist
            start = q.popleft()
            if start == N*N:
                return dist[start]
            
            for i in range(1,7):
                next = start + i
                row, col = get(next)
                if row <0 or row>=N or col<0 or col>=N:
                    continue
                if board[row][col] != -1:
                    next = board[row][col]
                if next in dist:
                    continue
                q.append(next)
                dist[next] = dist[start] + 1
        return -1
