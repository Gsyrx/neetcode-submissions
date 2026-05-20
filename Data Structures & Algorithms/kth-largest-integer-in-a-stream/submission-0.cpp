

class KthLargest {
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        // Add elements to the min-heap
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // If the heap has less than k elements, simply add the new element
        if (minHeap.size() < k) {
            minHeap.push(val);
        } 
        // If the heap already has k elements, we replace the root (smallest element)
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        // The root of the heap is the k-th largest element
        return minHeap.top();
    }
};
