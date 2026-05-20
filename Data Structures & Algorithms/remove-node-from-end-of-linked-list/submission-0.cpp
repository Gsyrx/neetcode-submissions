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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head to handle edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move `first` n+1 steps ahead to create a gap of n nodes between `first` and `second`
    for (int i = 0; i < n + 1; i++) {
        first = first->next;
    }

    // Move both `first` and `second` until `first` reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // `second` is now at the node before the one we want to delete
    second->next = second->next->next;

    // Return the new head (dummy->next can handle the case when the head is removed)
    return dummy->next;
    }
};
