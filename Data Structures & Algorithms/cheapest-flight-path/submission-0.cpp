class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // DP table to store the minimum prices
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        
        // Initially, the cost to reach src with 0 stops is 0
        dp[0][src] = 0;
        
        // Relax the edges for at most k+1 stops
        for (int i = 1; i <= k + 1; ++i) {
            // Copy the previous step's values (simulate no new stop, keep the previous minimum)
            dp[i] = dp[i - 1];
            
            // Process all flights and update the dp table
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], price = flight[2];
                
                // If there is a valid price to u and we can stop at i-1 stops, relax the edge
                if (dp[i - 1][u] != INT_MAX) {
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + price);
                }
            }
        }
        
        // The answer is the cheapest price to reach dst with at most k stops
        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};
