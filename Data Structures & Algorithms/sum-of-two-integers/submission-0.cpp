class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate carry and shift it left
            int carry = a & b;
            // Calculate sum without carry
            a = a ^ b;
            // Update b to the carry, shifted left by 1
            b = carry << 1;
        }
        return a;
    }
};
