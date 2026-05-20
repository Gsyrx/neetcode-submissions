class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        // Frequency map for characters in `t`
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }

        // Sliding window variables
        unordered_map<char, int> windowFreq;
        int left = 0, right = 0;
        int required = tFreq.size(); // Number of unique characters in `t`
        int formed = 0;             // Number of unique characters in the window matching `tFreq`
        int minLength = INT_MAX;    // Minimum window length
        int start = 0;              // Start index of the minimum window

        // Start sliding the window
        while (right < s.size()) {
            char c = s[right];
            windowFreq[c]++;

            // If the current character matches the required frequency, increment `formed`
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try to shrink the window while it is valid
            while (left <= right && formed == required) {
                char cLeft = s[left];

                // Update the minimum window size
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove the left character from the window
                windowFreq[cLeft]--;
                if (tFreq.count(cLeft) && windowFreq[cLeft] < tFreq[cLeft]) {
                    formed--;
                }

                left++; // Move the left pointer
            }

            // Expand the window by moving the right pointer
            right++;
        }

        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }
};
