class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base Case: If the current string is of length 2n, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an opening bracket '(' if we haven't used all 'n' opening brackets
        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }

        // Add a closing bracket ')' if it won't exceed the number of opening brackets
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};