class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result array with 1s

        // Step 1: Compute left product for each index
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = leftProduct; // Store product of elements to the left
            leftProduct *= nums[i]; // Update leftProduct
        }

        // Step 2: Compute right product and update result
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct; // Multiply with product of elements to the right
            rightProduct *= nums[i]; // Update rightProduct
        }

        return result;
    }
};
