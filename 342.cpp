class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&(num-1)) == 0 && num&0x55555555;
    }
};
/*
 * 0b100        4
 * 0b100 00     16
 * 0b100 00 00  64 
 * 
 * >>> bin(0x55555555)
 * '0b1010101010101010101010101010101'
 * the integer which is a power of 4, whose 1 bit always appear on odd position.
 * /
