class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        
        while (x != 0) {
            // Extract the last digit
            int digit = x % 10;
            // Check for overflow before updating the reversed number
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
                return 0;  // Overflow condition
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
                return 0;  // Underflow condition
            }
            // Update the reversed number
            reversed = reversed * 10 + digit;
            // Remove the last digit from x
            x /= 10;
        }
        
        return reversed;
    }
};
