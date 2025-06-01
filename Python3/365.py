class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if x + y < target:
            return False
        if x + y == target:
            return True
        gcd = self.GCD(x, y)
        return target%gcd == 0
        

    def GCD(self, x, y):
        if x > y:
            return self.GCD(y, x)
        while x != 0:
            temp = x
            x = y%x
            y = temp
        return y
