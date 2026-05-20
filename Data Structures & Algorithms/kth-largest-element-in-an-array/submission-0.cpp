class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the numbers in the array
    for (int num : nums) {
        minHeap.push(num); // Add the current number to the heap
        
        // If the heap size exceeds k, remove the smallest element (heap root)
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // The root of the min-heap will be the k-th largest element
    return minHeap.top();
    }
};
