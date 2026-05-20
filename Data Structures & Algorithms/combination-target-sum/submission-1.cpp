class Solution {
public:
    void backtrack(int index, vector<int>& nums, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);    // Found a valid combination
            return;
        }
        if (target < 0 || index == nums.size()) {
            return;                      // Invalid combination, backtrack
        }

        // Include nums[index]
        current.push_back(nums[index]);
        backtrack(index, nums, target - nums[index], current, result); // Stay at the same index (reuse allowed)
        current.pop_back();               // Backtrack

        // Exclude nums[index] and move to the next number
        backtrack(index + 1, nums, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, target, current, result);
        return result;
    }
};