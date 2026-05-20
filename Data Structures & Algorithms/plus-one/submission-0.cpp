class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;  // No carry, just add 1
                return digits;
            }
            digits[i] = 0;  // Carry over, set the current digit to 0
        }
        
        // If we've gone through all digits and there's still a carry
        digits.insert(digits.begin(), 1);  // Insert 1 at the beginning
        
        return digits;
    }
};
