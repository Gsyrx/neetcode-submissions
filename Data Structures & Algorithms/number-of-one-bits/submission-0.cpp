class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += (n & 1); // Add 1 if the least significant bit is 1
            n >>= 1;           // Right shift the number by 1 bit
        }
        return count;
    }
};
