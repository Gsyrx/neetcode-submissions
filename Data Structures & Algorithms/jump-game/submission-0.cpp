class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current index is beyond the max reachable index, return false
            if (i > max_reach) {
                return false;
            }
            
            // Update the max reachable index
            max_reach = max(max_reach, i + nums[i]);
            
            // If we can already reach or exceed the last index, return true
            if (max_reach >= nums.size() - 1) {
                return true;
            }
        }
        
        // Return true if we can reach the last index
        return max_reach >= nums.size() - 1;
    }
};
