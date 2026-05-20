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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if the list is empty or has less than k nodes
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }
        
        // If we have less than k nodes left, return the current head as is
        if (count < k) return head;

        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Now the head of the reversed part is 'prev'
        // Recursively reverse the remaining list and connect it with the current reversed part
        if (curr != nullptr) {
            head->next = reverseKGroup(curr, k);
        }

        // 'prev' is the new head of the reversed list
        return prev;
    }
};
