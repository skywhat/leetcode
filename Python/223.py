class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        # two rectangles don't overlap
        if C<=E or G<=A or B>=H or F>=D:
            return (C-A)*(D-B)+(G-E)*(H-F)
        new_r = [0,0,0,0]
        new_r[0] = max(A, E)
        new_r[1] = max(B, F)
        new_r[2] = min(C, G)
        new_r[3] = min(D, H)
        return (C-A)*(D-B)+(G-E)*(H-F)-abs(new_r[2]-new_r[0])*abs(new_r[3]-new_r[1])
        
