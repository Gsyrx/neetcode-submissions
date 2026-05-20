/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Comparison function for the priority queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on value
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Step 1: Add the first node of each list to the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify the result list
        ListNode* current = dummy;  // Pointer to construct the merged list
        
        // Step 2: Process the heap to merge the lists
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();  // Get the smallest node
            minHeap.pop();  // Remove the smallest node
            
            current->next = node;  // Attach the node to the merged list
            current = current->next;  // Move the pointer to the new node
            
            // If there is a next node in the same list, push it to the heap
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;  // Return the merged list (skip the dummy node)
    }
};
