class Solution {
public:

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Every time we add a subset to the result
        result.push_back(current);
        
        // Explore further by adding more elements to the current subset
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);  // Include nums[i] in the subset
            backtrack(nums, i + 1, current, result);  // Recur with the next element
            current.pop_back();  // Backtrack: remove nums[i] from the subset
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};
