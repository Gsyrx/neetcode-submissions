class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;  // Empty string can always be segmented
        
        // Loop through each position in the string
        for (int i = 1; i <= s.size(); ++i) {
            // Check each possible starting point j for the substring ending at i
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // No need to check further for this i
                }
            }
        }
        
        return dp[s.size()];
    }
};
