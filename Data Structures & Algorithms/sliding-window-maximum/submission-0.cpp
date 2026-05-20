class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // Store the maximums of each window
    deque<int> dq;      // Deque to store indices

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices of smaller elements from the back of the deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element index to the deque
        dq.push_back(i);

        // Add the maximum for the current window to the result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;

    }
};
