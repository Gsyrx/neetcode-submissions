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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Ensure we are operating in a BST (binary search tree)
        while (root) {
            // If both nodes p and q are smaller, move to the right subtree
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // If both nodes p and q are larger, move to the left subtree
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If one is on the left and the other is on the right (or if we find either p or q), root is the LCA
            else {
                return root;
            }
        }
        return nullptr;
    }
};
