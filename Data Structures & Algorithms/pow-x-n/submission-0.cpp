class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case where n is 0
        if (n == 0) return 1.0;

        // Handle the case of negative exponent
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        // Compute the power using exponentiation by squaring
        double result = 1.0;
        while (n > 0) {
            if (n % 2 == 1) { // If n is odd
                result *= x;
            }
            x *= x; // Square the base
            n /= 2; // Halve the exponent
        }

        return result;
    }
};
