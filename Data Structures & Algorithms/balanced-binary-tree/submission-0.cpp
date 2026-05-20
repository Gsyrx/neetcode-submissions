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

// Helper function to calculate the height of the tree and check balance
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;  // Base case: empty subtree has height 0

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = dfs(node->left);
        if (leftHeight == -1) return -1;  // If the left subtree is unbalanced, propagate -1

        int rightHeight = dfs(node->right);
        if (rightHeight == -1) return -1;  // If the right subtree is unbalanced, propagate -1

        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Unbalanced
        }

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }
    
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;  // If dfs returns -1, it means unbalanced
    }
};
