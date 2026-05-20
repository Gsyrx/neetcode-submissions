/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void inorder(TreeNode* node, int k, int& count, int& result) {
        if (node == nullptr) return;
        
        // Traverse the left subtree
        inorder(node->left, k, count, result);
        
        // Visit the current node
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        
        // Traverse the right subtree
        inorder(node->right, k, count, result);
    }

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }
};
