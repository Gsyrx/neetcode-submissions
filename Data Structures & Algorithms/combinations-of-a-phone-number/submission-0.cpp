class Solution {
public:

    // Backtracking function
    void backtrack(const string& digits, int index, string& current, 
                   const vector<string>& mapping, vector<string>& result) {
        // Base case: If the current combination is complete (i.e., the length matches digits length)
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        // Try each letter and recurse
        for (char c : letters) {
            current.push_back(c);  // Choose the letter
            backtrack(digits, index + 1, current, mapping, result);  // Recur for the next digit
            current.pop_back();  // Backtrack, remove the last chosen letter
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;  // If input is empty, return empty result
        
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current;
        backtrack(digits, 0, current, mapping, result);
        return result;
    }
};
