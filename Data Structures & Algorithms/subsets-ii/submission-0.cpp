class Solution {
public:

    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Add the current subset to the result
        
        // Iterate through the remaining elements
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates: if the current element is the same as the previous one, and the previous one was not included, skip it
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);  // Include the current element
            backtrack(nums, i + 1, current, result);  // Recursively generate subsets from the next index
            current.pop_back();  // Backtrack by removing the last element
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        backtrack(nums, 0, current, result);  // Start backtracking from index 0
        return result;
    }
};
