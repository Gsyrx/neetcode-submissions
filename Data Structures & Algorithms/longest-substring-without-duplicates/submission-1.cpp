class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;  // To store the last index of each character
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If the character is already in the window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;  // Move the left pointer
            }

            charIndexMap[currentChar] = right;  // Update the last seen index of the character
            maxLength = max(maxLength, right - left + 1);  // Update the maximum length
        }

        return maxLength;
    }
};