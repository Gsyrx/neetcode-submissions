class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n + 1, 0); // Vector to store the number of 1's for each number
        
        // Iterate over each number from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Use the formula to compute the number of 1's
            count[i] = count[i >> 1] + (i & 1);
        }
        
        return count;
    }
};
