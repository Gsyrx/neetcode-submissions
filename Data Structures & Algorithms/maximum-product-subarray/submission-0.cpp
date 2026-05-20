class Solution {
public:
    int maxProduct(vector<int>& nums) {
            if (nums.empty()) return 0;  // Edge case: empty array
    
    int max_prod = nums[0];  // Maximum product so far
    int min_prod = nums[0];  // Minimum product so far
    int result = nums[0];    // Store the final result
    
    // Start from the second element
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            // Swap max_prod and min_prod if the current number is negative
            swap(max_prod, min_prod);
        }
        
        // Update max_prod and min_prod
        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);
        
        // Update the result
        result = max(result, max_prod);
    }
    
    return result;
    }
};
