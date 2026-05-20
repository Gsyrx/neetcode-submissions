class Solution {
public:

    // Function to perform backtracking
    void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        // Base case: If we reach the end of the string, add the current partition to result
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.length(); ++end) {
            string substring = s.substr(start, end - start);
            
            // If the substring is a palindrome, continue exploring
            if (isPalindrome(substring)) {
                current.push_back(substring);  // Add palindrome substring to current partition
                backtrack(s, end, current, result);  // Recur for the next part of the string
                current.pop_back();  // Backtrack, remove the last added palindrome
            }
        }
    }


        // Function to check if a string is a palindrome
    bool isPalindrome(const string& str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
};
