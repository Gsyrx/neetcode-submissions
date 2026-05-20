class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // DP table initialization
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;  // Deleting all characters from word1
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;  // Inserting all characters into word1
        }

        // DP table filling
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],   // Deletion
                                        dp[i][j - 1],   // Insertion
                                        dp[i - 1][j - 1]});  // Substitution
                }
            }
        }

        return dp[m][n];  // The result is in the bottom-right corner of the DP table
    }
};
