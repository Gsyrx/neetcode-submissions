class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            // Initialize DP array, dp[i] will be the minimum coins needed for amount i
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // No coins needed to make amount 0

    // Loop through each coin
    for (int coin : coins) {
        // Update DP table for all amounts that can be formed by adding this coin
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, return -1 (impossible to form the amount)
    return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
