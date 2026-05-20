class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if (currentSum == target) {
                // Return the 1-based index positions
                return {left + 1, right + 1};
            } else if (currentSum < target) {
                left++;  // Move the left pointer to the right to increase the sum
            } else {
                right--;  // Move the right pointer to the left to decrease the sum
            }
        }
        
        return {};  // In case no solution is found, though it's assumed there will be one
    }
};
