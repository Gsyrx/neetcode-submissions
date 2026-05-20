class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Add 1 to both ends of the array to simplify boundary conditions
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over the subarrays of length 2 to n
        for (int length = 2; length < n; ++length) {
            for (int left = 0; left < n - length; ++left) {
                int right = left + length;
                // Try every possible balloon to burst
                for (int k = left + 1; k < right; ++k) {
                    dp[left][right] = max(dp[left][right], dp[left][k] + dp[k][right] + nums[left] * nums[k] * nums[right]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
