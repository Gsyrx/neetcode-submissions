class Solution {
public:

void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: if the current string has reached the required length
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an open parenthesis if possible
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // Backtrack
        }

        // Add a close parenthesis if valid
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // Backtrack
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
