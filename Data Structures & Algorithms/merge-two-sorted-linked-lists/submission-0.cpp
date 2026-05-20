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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the process of merging
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy; // Pointer to the current node in the merged list
    
    // Merge the two lists until one of them is exhausted
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            current->next = list1;  // Attach list1's node
            list1 = list1->next;    // Move list1 pointer forward
        } else {
            current->next = list2;  // Attach list2's node
            list2 = list2->next;    // Move list2 pointer forward
        }
        current = current->next;  // Move the current pointer to the newly added node
    }
    
    // If either list1 or list2 is not exhausted, append the remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    } else if (list2 != nullptr) {
        current->next = list2;
    }
    
    // Return the merged list, which starts from dummy->next
    return dummy->next;
    }
};
