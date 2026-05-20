class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP array to store the number of paths
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Start filling the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // The number of ways to reach dp[i][j] is the sum of the number of ways
                // to reach the cell above it and the cell to the left of it
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // The answer will be in the bottom-right corner
        return dp[m-1][n-1];
    }
};
