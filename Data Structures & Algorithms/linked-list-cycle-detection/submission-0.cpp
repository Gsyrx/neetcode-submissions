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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
        return false;  // Empty list or single element list has no cycle
    }

    ListNode* slow = head;    // Slow pointer (tortoise)
    ListNode* fast = head;    // Fast pointer (hare)

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by one step
        fast = fast->next->next;     // Move fast pointer by two steps

        if (slow == fast) {
            return true;  // Cycle detected, slow and fast pointers meet
        }
    }

    return false;  // No cycle detected, fast pointer reached end of list
    }
};
