class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if target is found
            if (nums[mid] == target) {
                return mid;
            }
            
            // Adjust search bounds
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // If target is not found
        return -1;
    }
};
