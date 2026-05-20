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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  // Initially, prev is set to nullptr.
    ListNode* curr = head;     // Start with the head of the list.
    
    while (curr != nullptr) {
        ListNode* next = curr->next; // Save the next node.
        curr->next = prev;           // Reverse the current node's pointer.
        prev = curr;                 // Move prev and curr one step forward.
        curr = next;
    }
    
    return prev; // After the loop, prev will point to the new head of the reversed list.
    }
};
