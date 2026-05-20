class MedianFinder {
private:
    priority_queue<int> left;                         // Max-heap (stores the smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // Min-heap (stores the larger half)

public:
    MedianFinder() {
        // Constructor
    }
    
    // Add a number to the data stream
    void addNum(int num) {
        left.push(num);                // Step 1: Add to max-heap

        // Step 2: Balance - move the largest from 'left' to 'right'
        right.push(left.top());
        left.pop();

        // Step 3: Maintain size property (left can have at most 1 more element than right)
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    // Find the median
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();         // Odd case: median is the max of 'left'
        } else {
            return (left.top() + right.top()) / 2.0; // Even case: average of both heaps' tops
        }
    }
};
