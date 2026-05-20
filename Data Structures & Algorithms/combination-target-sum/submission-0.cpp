class Solution {
public:

    void backtrack(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // If the target is exactly zero, we've found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Explore further by adding numbers from the current index onward
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) continue; // Skip numbers that exceed the target
            current.push_back(nums[i]);  // Include nums[i] in the combination
            backtrack(nums, target - nums[i], i, current, result);  // Recur with the reduced target
            current.pop_back();  // Backtrack: remove nums[i] from the combination
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());  // Sort to make sure combinations are generated in an ordered manner
        backtrack(nums, target, 0, current, result);
        return result;
    }
};
