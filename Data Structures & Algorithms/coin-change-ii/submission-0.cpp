class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Initialize a dp array with size amount + 1 and set all values to 0
        vector<int> dp(amount + 1, 0);
        
        // Base case: There's 1 way to make amount 0 (no coins)
        dp[0] = 1;
        
        // For each coin, update the dp array for all amounts from coin to amount
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];  // Add the ways to make (i - coin) to dp[i]
            }
        }
        
        // The result is the number of ways to make the target amount
        return dp[amount];
    }
};
