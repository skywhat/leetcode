class Solution:
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        count = Counter()
        for x, y in coordinates:
            for p, q in [[x-1, y-1], [x-1, y], [x, y-1], [x, y]]:
                if p<0 or p>=m-1 or q<0 or q>=n-1:
                    continue
                count[(p, q)] +=1
        res = [0]*5
        for val in count.values():
            res[val] +=1
        res[0] = (m-1)*(n-1) - sum(res[1:])
        return res
