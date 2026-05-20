class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Add the current subset to the result

        // Explore further elements
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);        // Include nums[i]
            backtrack(i + 1, nums, current, result);  // Move to the next element
            current.pop_back();                // Backtrack (remove the last element)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);
        return result;
    }
};