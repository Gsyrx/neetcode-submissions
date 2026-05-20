class Solution {
public:

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: when start index reaches the end of the array, add the current permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Generate all permutations by swapping each element into the "start" position
        for (int i = start; i < nums.size(); i++) {
            // Swap nums[start] with nums[i]
            swap(nums[start], nums[i]);
            // Recur to generate the permutations with the new array configuration
            backtrack(nums, start + 1, result);
            // Backtrack by swapping back
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};
