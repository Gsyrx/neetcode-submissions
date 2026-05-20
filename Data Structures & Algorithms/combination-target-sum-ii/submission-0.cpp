class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);  // If we've reached the target, add the combination to the result
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // If the current number is greater than the target, break (no need to continue as array is sorted)
            if (candidates[i] > target) break;
            
            // Skip duplicates: If the current number is the same as the previous one, skip it to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            current.push_back(candidates[i]);  // Include the current number
            backtrack(candidates, target - candidates[i], i + 1, current, result);  // Recurse with reduced target and the next index
            current.pop_back();  // Backtrack by removing the last number
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());  // Sort the candidates to help with skipping duplicates
        backtrack(candidates, target, 0, current, result);  // Start backtracking from index 0
        return result;
    }
};
