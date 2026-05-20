class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
vector<vector<int>> result;
        
        // Sort the array
        sort(nums.begin(), nums.end());

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements to avoid repeated triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            // Use two-pointer technique to find the other two numbers
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move left and right to the next distinct elements
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
