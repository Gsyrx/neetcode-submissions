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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify the code
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;  // Get the value from l1, or 0 if l1 is exhausted
            int y = (l2 != nullptr) ? l2->val : 0;  // Get the value from l2, or 0 if l2 is exhausted
            int sum = x + y + carry;  // Add the two digits and the carry

            carry = sum / 10;  // Calculate the carry for the next iteration
            current->next = new ListNode(sum % 10);  // Create a new node with the current sum (mod 10)
            
            current = current->next;  // Move to the next node in the result list
            
            // Move to the next nodes in the input lists if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;  // Return the next of dummy node, which is the head of the result list
    }
};
