class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D dp array initialized to 0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Fill the first row and first column with 1 (base case)
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        
        // Fill the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        // The result is in the bottom-right corner of the grid
        return dp[m - 1][n - 1];
    }
};
