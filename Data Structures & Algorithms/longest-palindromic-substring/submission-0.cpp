class Solution {
public:
    string longestPalindrome(string s) {
            int n = s.size();
    if (n == 0) return "";

    // dp[i][j] will be true if substring s[i...j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string longest = "";

    // Single character substrings are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        longest = s[i];  // A single character is always a palindrome
    }

    // Check substrings of length 2 or greater
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;  // j is the end index of the substring
            if (s[i] == s[j]) {
                if (length == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (length > longest.size()) {
                        longest = s.substr(i, length);
                    }
                }
            }
        }
    }

    return longest;
    }
};
