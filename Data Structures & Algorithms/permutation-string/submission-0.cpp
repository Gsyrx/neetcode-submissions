class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    
    // If s1 is longer than s2, no permutation can exist
    if (n > m) return false;
    
    // Frequency map for s1
    unordered_map<char, int> s1Freq;
    for (char c : s1) {
        s1Freq[c]++;
    }
    
    // Frequency map for the current window in s2
    unordered_map<char, int> windowFreq;
    
    // Number of valid characters matched
    int matchCount = 0;
    
    // Sliding window: Two pointers technique
    for (int right = 0; right < m; right++) {
        char cRight = s2[right];
        
        // If the character is part of s1, we count it in the window
        if (s1Freq.find(cRight) != s1Freq.end()) {
            windowFreq[cRight]++;
            
            // If the current character count matches the target frequency in s1
            if (windowFreq[cRight] == s1Freq[cRight]) {
                matchCount++;
            }
        }
        
        // Shrink the window from the left if the window size exceeds s1's size
        if (right >= n) {
            char cLeft = s2[right - n];
            
            // If the character is part of s1, decrease its count in the window
            if (s1Freq.find(cLeft) != s1Freq.end()) {
                if (windowFreq[cLeft] == s1Freq[cLeft]) {
                    matchCount--;
                }
                windowFreq[cLeft]--;
            }
        }
        
        // If all characters match, return true
        if (matchCount == s1Freq.size()) {
            return true;
        }
    }
    
    // If no valid window was found, return false
    return false;    
    }
};
