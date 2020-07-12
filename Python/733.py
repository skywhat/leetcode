class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        self.changeColor(image, sr, sc, image[sr][sc], newColor)
        return image

        
    def changeColor(self, image, i, j, oldColor, newColor):
        if i <0 or i>= len(image) or j<0 or j>=len(image[0]):
            return
        if image[i][j] == newColor or image[i][j] != oldColor:
            return
        image[i][j] = newColor
        for x, y in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            self.changeColor(image, i+x, j+y, oldColor, newColor)
