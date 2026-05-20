class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;  // Stack to hold operands

        for (string& token : tokens) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();  // Second operand
                int a = st.top(); st.pop();  // First operand

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);  // Truncates towards zero
            }
            // If token is a number
            else {
                st.push(stoi(token));  // Convert string to integer and push
            }
        }

        return st.top();  // Final result
    }
};
