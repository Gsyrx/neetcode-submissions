class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freqMap;

    // Traverse the array
    for (int num : nums) {
        // If the number is already in the map, it's the duplicate
        if (freqMap.find(num) != freqMap.end()) {
            return num;
        }
        // Otherwise, store the number in the map
        freqMap[num] = 1;
    }

    // In case there is no duplicate (which won't happen in this problem)
    return -1; 
    }
};
