class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the area between the two pointers
            int currentArea = min(heights[left], heights[right]) * (right - left);

            // Update maxArea if currentArea is larger
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
