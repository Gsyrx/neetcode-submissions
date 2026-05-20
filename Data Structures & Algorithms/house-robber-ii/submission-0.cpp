class Solution {
public:

int robHelper(vector<int>& nums, int start, int end) {
    int prev2 = 0;  // prev2 is the value when not picking the current house
    int prev1 = 0;  // prev1 is the value when picking the current house
    
    for (int i = start; i <= end; ++i) {
        int temp = prev1;
        prev1 = max(prev1, prev2 + nums[i]); // Pick or don't pick the current house
        prev2 = temp;
    }
    
    return prev1;
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // No houses to rob
        if (n == 1) return nums[0];  // Only one house to rob

        // Two cases: Rob houses from 0 to n-2 or from 1 to n-1
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1)); 
    }
};
