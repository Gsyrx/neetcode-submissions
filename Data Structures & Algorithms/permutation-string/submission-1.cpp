class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // Sliding window on s2
        for (int i = 0; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;  // Add new character to window

            // Remove character left out of the window
            if (i >= s1.length()) {
                freq2[s2[i - s1.length()] - 'a']--;
            }

            // Compare frequency arrays
            if (freq1 == freq2) return true;
        }

        return false;
    }
};