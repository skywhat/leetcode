class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        s = set([self.dist(p1,p2), self.dist(p1,p3), self.dist(p1, p4), self.dist(p2,p3), self.dist(p2, p4), self.dist(p3, p4)])
        if len(s) !=2 or 0 in s:
            return False
        return True
        
        
    def dist(self, p1, p2):
        return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2
