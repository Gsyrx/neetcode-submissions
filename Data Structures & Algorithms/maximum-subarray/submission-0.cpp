class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // Update the current sum, either adding the current number or starting fresh from the current number
        currentSum = max(nums[i], currentSum + nums[i]);
        
        // Update the maximum sum found so far
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
    }
};
