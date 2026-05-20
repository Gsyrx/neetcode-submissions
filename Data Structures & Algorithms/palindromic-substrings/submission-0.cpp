class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        // For each character in the string, expand around it as a center
        for (int i = 0; i < n; ++i) {
            // Odd length palindromes (centered at s[i])
            count += expandAroundCenter(s, i, i);
            // Even length palindromes (centered between s[i] and s[i+1])
            count += expandAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
private:
    // Helper function to expand around a center and count palindromes
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        
        // Expand outwards while the substring is a palindrome
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;  // We found a palindrome
            --left;
            ++right;
        }
        
        return count;
    }
};
