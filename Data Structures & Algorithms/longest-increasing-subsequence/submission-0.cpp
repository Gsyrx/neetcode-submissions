class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1);  // Initialize dp array, each element is at least a subsequence of length 1

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {  // If nums[i] can extend the subsequence ending at nums[j]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The length of the longest increasing subsequence will be the max value in dp
    return *max_element(dp.begin(), dp.end());
    }
};
