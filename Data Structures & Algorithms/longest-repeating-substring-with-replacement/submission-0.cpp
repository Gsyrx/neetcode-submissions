class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;  // Frequency map to store character frequencies
        int maxLength = 0;  // Maximum length of valid substring
        int maxFreq = 0;    // Maximum frequency of a single character in the window
        int start = 0;      // Start pointer of the sliding window

        // Iterate through the string with the end pointer
        for (int end = 0; end < s.size(); ++end) {
            // Update frequency map with the current character
            freqMap[s[end]]++;

            // Update the maximum frequency of a single character in the window
            maxFreq = max(maxFreq, freqMap[s[end]]);

            // If the window size minus the max frequency exceeds k, shrink the window
            if (end - start + 1 - maxFreq > k) {
                freqMap[s[start]]--;  // Decrease the frequency of the character at the start
                start++;  // Move the start pointer forward
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
