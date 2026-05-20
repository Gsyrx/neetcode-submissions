class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;

    // Calculate the total sum of the array
    for (int num : nums) {
        total_sum += num;
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (total_sum % 2 != 0) return false;

    // Target sum is half of the total sum
    int target = total_sum / 2;
    
    // DP array to track if a subset sum is possible
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // A sum of 0 is always possible (empty subset)

    // Loop through each number in the array
    for (int num : nums) {
        // Update the dp array in reverse to avoid using the same element twice
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    // The answer is whether we can form the subset with sum equal to target
    return dp[target];
    }
};
