/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
            if (!head) return nullptr;

    // Step 1: Create new nodes and interleave them
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->val); // Create a new node
        newNode->next = curr->next; // Point it to the next node of the original list
        curr->next = newNode; // Insert the new node right after the original node
        curr = newNode->next; // Move to the next original node
    }

    // Step 2: Set the random pointers for the new nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next; // Set the random pointer of the new node
        }
        curr = curr->next->next; // Move to the next original node
    }

    // Step 3: Separate the copied list from the original list
    curr = head;
    Node* newHead = head->next; // The head of the copied list
    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next; // Restore the next pointer of the original list
        if (copy->next) {
            copy->next = copy->next->next; // Move to the next copied node
        }
        curr = curr->next;
    }

    return newHead;
    }
};
