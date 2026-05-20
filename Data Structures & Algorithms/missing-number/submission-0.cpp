class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate the expected sum using the formula
        int expectedSum = n * (n + 1) / 2;
        
        // Calculate the actual sum of the elements in the array
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        // The missing number is the difference between expected and actual sum
        return expectedSum - actualSum;
    }
};
