class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }

    // int robFrom(vector<int>& nums, int i, vector<int>& memo) {
    //     // Base cases
    //     if (i < 0) return 0; // No house left to rob
    //     if (memo[i] != -1) return memo[i]; // Use cached result

    //     // Decision: rob current house or skip it
    //     int robCurrent = nums[i] + robFrom(nums, i - 2, memo);
    //     int skipCurrent = robFrom(nums, i - 1, memo);

    //     // Store the result and return the maximum
    //     memo[i] = max(robCurrent, skipCurrent);
    //     return memo[i];
    // }
    
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> memo(n, -1);
    //     return robFrom(nums, n - 1, memo);
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     // Edge cases
    //     if (n == 0) return 0;
    //     if (n == 1) return nums[0];

    //     // Use two variables to track the maximum sum including/excluding the current house
    //     int prev1 = 0, prev2 = 0;

    //     for (int num : nums) {
    //         int current = max(prev2 + num, prev1);
    //         prev2 = prev1;
    //         prev1 = current;
    //     }

    //     return prev1;
    // }
};
