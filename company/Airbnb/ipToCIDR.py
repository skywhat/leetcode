class Solution:
    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        num = self.ipTonum(ip)
        result = []
        while n>0:
            lb = self.lowBitValue(num)
            while lb > n:
                lb = lb//2
            n -= lb
            result.append(self.numToip(num) + "/" + str(32-self.lowBit(lb)))
            num += lb

        return result

    def lowBitValue(self, num):
        return 1<<self.lowBit(num)

    def lowBit(self, num):
        for i in range(32):
            if num& (1<<i):
                return i
        return 0

    def ipTonum(self, ip):
        nums = map(int, ip.split('.'))
        return (nums[0]<<24) + (nums[1]<<16) + (nums[2]<<8) + nums[3];

    def numToip(self, num):
        return '.'.join([str(num>>24), str(num>>16 & 0xff), str(num>>8 & 0xff), str(num & 0xff)]);


s = Solution()

ip = "255.0.0.7"
n=10
res = s.ipToCIDR(ip, n)
print res

ip = "255.0.0.7"
n=1
res = s.ipToCIDR(ip, n)
print res

ip = "255.0.0.7"
n=9
res = s.ipToCIDR(ip, n)
print res

ip = "255.0.0.7"
n=256
res = s.ipToCIDR(ip, n)
print res
