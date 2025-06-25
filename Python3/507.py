class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        total = 1
        for i in range(2, math.ceil(math.sqrt(num))):
            if num%i == 0:
                total += i + num/i
        return total == num
