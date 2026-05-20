class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        // Edge case: empty string or starts with '0' (invalid)
        if (n == 0 || s[0] == '0') return 0;
        
        // dp[i] represents the number of ways to decode s[0..i-1]
        vector<int> dp(n + 1, 0);
        
        // There's one way to decode an empty string
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;  // If the first character is '0', it's invalid
        
        for (int i = 2; i <= n; ++i) {
            // Check if the current single digit is valid
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Check if the current two digits form a valid number
            int twoDigit = stoi(s.substr(i-2, 2));  // Extract two characters and convert to an integer
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};
