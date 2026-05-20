class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int waterTrapped = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // If current height at left is less than right, process the left side
                if (height[left] >= left_max) {
                    left_max = height[left];  // Update left_max
                } else {
                    waterTrapped += left_max - height[left];  // Calculate water trapped
                }
                left++;  // Move left pointer to the right
            } else {
                // If current height at right is less or equal to left, process the right side
                if (height[right] >= right_max) {
                    right_max = height[right];  // Update right_max
                } else {
                    waterTrapped += right_max - height[right];  // Calculate water trapped
                }
                right--;  // Move right pointer to the left
            }
        }

        return waterTrapped;
    }
};
