class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, -1);
        vector<int> result;
        
        // Record the last index of each character
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        int start = 0, end = 0;
        
        // Traverse the string again to partition it
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastIndex[s[i] - 'a']);
            
            // If we've reached the end of the current partition
            if (i == end) {
                result.push_back(i - start + 1); // Add the partition length
                start = i + 1; // Start a new partition
            }
        }
        
        return result;
    }
};
