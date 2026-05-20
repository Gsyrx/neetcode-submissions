class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // If the length of s1 + s2 doesn't match the length of s3, return false
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        // Initialize a DP table with false values
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        // Base case: empty s1 and empty s2 can form empty s3
        dp[0][0] = true;

        // Fill the DP table
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        // The result will be in the bottom-right cell
        return dp[s1.size()][s2.size()];
    }
};
