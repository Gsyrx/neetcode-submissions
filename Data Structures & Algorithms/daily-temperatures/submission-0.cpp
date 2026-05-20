class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Initialize the result array with 0s.
        stack<int> st;  // Stack to store indices of temperatures array.

        for (int i = 0; i < n; i++) {
            // Check if the current temperature is higher than the one at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                result[index] = i - index;  // The difference between the current day and the previous day
            }

            // Push the current index onto the stack
            st.push(i);
        }

        return result;
    }
};
