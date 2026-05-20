class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;  // Hash map to store the most recent index of each character
        int maxLength = 0;  // Variable to store the length of the longest substring
        int start = 0;  // Start pointer of the sliding window

        // Iterate over each character with the end pointer
        for (int end = 0; end < s.size(); ++end) {
            // If the character is already in the window, move the start pointer
            if (charMap.find(s[end]) != charMap.end() && charMap[s[end]] >= start) {
                start = charMap[s[end]] + 1;  // Move start to one past the last occurrence of s[end]
            }
            // Update the most recent index of the character
            charMap[s[end]] = end;
            // Calculate the length of the current window and update maxLength
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;       
    }
};
