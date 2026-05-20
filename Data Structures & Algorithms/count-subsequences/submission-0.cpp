class Solution {
public:
    int numDistinct(string s, string t) {
                int m = s.size();
        int n = t.size();
        
        // dp[i][j] will store the number of ways to form the first j characters of t from the first i characters of s
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // Base case: There's 1 way to form the empty string t from any prefix of s
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // The answer is in dp[m][n]
        return dp[m][n];
    }
};
