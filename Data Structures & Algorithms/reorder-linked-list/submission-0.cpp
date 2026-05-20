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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
        return;  // If the list has 0 or 1 node, no reordering needed
    }

    // Step 1: Find the middle of the list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;  // Split the list into two halves
    ListNode* prev = nullptr;
    
    while (secondHalf) {
        ListNode* nextNode = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = nextNode;
    }

    // Now 'prev' points to the head of the reversed second half

    // Step 3: Merge the two halves
    ListNode* firstHalf = head;
    secondHalf = prev;  // 'secondHalf' is now the reversed second half

    while (secondHalf) {
        ListNode* temp1 = firstHalf->next;
        ListNode* temp2 = secondHalf->next;
        
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        
        firstHalf = temp1;
        secondHalf = temp2;
    }
    }
};
