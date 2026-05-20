class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);     // Initialize result with zeros
        stack<int> st;                // Monotonic decreasing stack (stores indices)

        for (int i = 0; i < n; i++) {
            // Check if current temperature is greater than the temperature at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;  // Number of days to wait
            }
            st.push(i);  // Push current index onto the stack
        }

        return result;
    }
};