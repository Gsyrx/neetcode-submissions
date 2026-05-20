class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false; // Different lengths can't be anagrams
        }

        unordered_map<char, int> freq; // Frequency map for characters

        // Count frequency of characters in 's'
        for (char ch : s) {
            freq[ch]++;
        }

        // Decrease frequency based on 't'
        for (char ch : t) {
            freq[ch]--;
            if (freq[ch] < 0) {
                return false; // More occurrences in 't' than in 's'
            }
        }

        return true; // All frequencies matched
    }
};