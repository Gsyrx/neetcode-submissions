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

bool isValid(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true; // An empty node is a valid BST
        
        // Check if the current node's value is within the valid range
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isValid(node->left, minVal, node->val) && isValid(node->right, node->val, maxVal);
    }

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX); // Initialize with the minimum and maximum possible values
    }
};
