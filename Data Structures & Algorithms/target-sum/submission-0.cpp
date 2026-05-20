class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Calculate the sum of all elements in the array
        int sumTotal = 0;
        for (int num : nums) {
            sumTotal += num;
        }

        // If (target + sumTotal) is odd or target is out of the range [-sumTotal, sumTotal], return 0
        if ((target + sumTotal) % 2 != 0 || abs(target) > sumTotal) {
            return 0;
        }

        // The sum we are looking for is (target + sumTotal) / 2
        int sumPos = (target + sumTotal) / 2;

        // Initialize a dp array where dp[i] represents the number of ways to make sum i
        vector<int> dp(sumPos + 1, 0);
        dp[0] = 1; // There's 1 way to make sum 0 (by not selecting any elements)

        // Process each number in the array
        for (int num : nums) {
            // Iterate backward to avoid using the same number more than once
            for (int i = sumPos; i >= num; --i) {
                dp[i] += dp[i - num];  // Add the number of ways to form (i - num)
            }
        }

        // The result is the number of ways to form the sum sumPos
        return dp[sumPos];
    }
};
