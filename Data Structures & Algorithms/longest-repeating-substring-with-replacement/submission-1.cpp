class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // Frequency of each character
        int left = 0, maxCount = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;  // Update frequency
            maxCount = max(maxCount, freq[s[right] - 'A']);  // Most frequent char in the window

            // Check if replacements exceed k
            if ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;  // Shrink the window
                left++;
            }

            maxLength = max(maxLength, right - left + 1);  // Update max length
        }

        return maxLength;
    }
};