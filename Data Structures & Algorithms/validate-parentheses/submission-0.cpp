class Solution {
public:
    bool isValid(string s) {
    stack<char> st;  // Stack to store opening brackets
    unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        // If it's a closing bracket
        if (matching.count(c)) {
            // Check if the top of the stack matches the expected opening bracket
            if (!st.empty() && st.top() == matching[c]) {
                st.pop();
            } else {
                return false;
            }
        } else {
            // It's an opening bracket, push it onto the stack
            st.push(c);
        }
    }

    // If the stack is empty, all brackets were matched
    return st.empty();   
    }
};
