class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;
    
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (valueToIndex.find(complement) != valueToIndex.end()) {
                // Return the indices with the smaller index first
                return {valueToIndex[complement], i};
            }
            
            // Store the current number and its index
            valueToIndex[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though the problem guarantees one solution)
        return {}; 
    }
};
