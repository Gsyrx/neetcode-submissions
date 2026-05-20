class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq; // To store frequency of each number

        for (int num : nums) {
            freq[num]++; // Increment the count of the current number
            if (freq[num] > 1) {
                return true; // Duplicate found
            }
        }
        return false; // No duplicates
    }
};