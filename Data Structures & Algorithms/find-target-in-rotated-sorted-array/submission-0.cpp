class Solution {
public:
    int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If we found the target, return the index.
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // Target is in the left half
            } else {
                left = mid + 1;   // Target is in the right half
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;   // Target is in the right half
            } else {
                right = mid - 1;  // Target is in the left half
            }
        }
    }
    
    // If we reach here, the target was not found
    return -1;
    }
};
