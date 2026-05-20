class Solution {
public:
    int findDuplicate(vector<int>& nums) {
// Step 1: Detect the cycle using Floyd's Tortoise and Hare algorithm.
    int slow = nums[0];  // slow pointer starts at the first element
    int fast = nums[0];  // fast pointer also starts at the first element

    // Phase 1: Find the intersection point in the cycle.
    do {
        slow = nums[slow];           // Move slow pointer by 1 step
        fast = nums[nums[fast]];     // Move fast pointer by 2 steps
    } while (slow != fast);  // Continue until both pointers meet

    // Phase 2: Find the entrance to the cycle (duplicate number).
    slow = nums[0];  // Move slow pointer back to the start of the array
    while (slow != fast) {
        slow = nums[slow];  // Move slow pointer by 1 step
        fast = nums[fast];  // Move fast pointer by 1 step
    }

    return slow;  // The duplicate number
    }
};
