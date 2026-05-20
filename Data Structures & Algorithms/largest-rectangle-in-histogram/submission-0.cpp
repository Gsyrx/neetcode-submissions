class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Stack to store indices of the histogram bars
        int maxArea = 0;  // Variable to track the maximum area

        // Iterate through each bar of the histogram
        for (int i = 0; i < n; i++) {
            // While the current bar is shorter than the bar at the top of the stack
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];  // Height of the popped bar
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;  // Calculate width
                maxArea = max(maxArea, height * width);  // Update max area
            }
            st.push(i);  // Push the current index to the stack
        }

        // Final pass to handle remaining bars in the stack
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;  // Calculate width
            maxArea = max(maxArea, height * width);  // Update max area
        }

        return maxArea;
    }
};
