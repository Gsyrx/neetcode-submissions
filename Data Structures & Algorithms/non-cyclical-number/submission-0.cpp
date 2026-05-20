class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;  // Set to store numbers we've already encountered
        
        while (n != 1) {
            int sum = 0;
            
            // Calculate sum of squares of digits
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            
            // If the sum has already been seen, we are in a cycle
            if (seen.count(sum)) {
                return false;
            }
            
            // Add the sum to the set of seen numbers
            seen.insert(sum);
            n = sum;  // Move to the next number (sum of squares)
        }
        
        return true;  // If we reached 1, it's a happy number
    }
};
