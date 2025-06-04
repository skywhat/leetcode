class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        colors = [0]*n
        res = []
        cnt = 0
        for idx, color in queries:
            if color != colors[idx]:
                if idx > 0 and colors[idx] != 0 and colors[idx] == colors[idx-1] :
                    cnt -=1
                if idx < n-1 and colors[idx]!=0 and colors[idx] == colors[idx+1]:
                    cnt -=1
                if idx > 0 and color == colors[idx-1]:
                    cnt +=1
                if idx < n-1 and color == colors[idx+1]:
                    cnt +=1
                colors[idx] = color
            res.append(cnt)
        return res
