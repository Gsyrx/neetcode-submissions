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


 // Function to check if two trees are identical
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, the trees are identical
        if (root1 == nullptr && root2 == nullptr) return true;

        // If one is null and the other is not, they are not identical
        if (root1 == nullptr || root2 == nullptr) return false;

        // If the values don't match, return false
        if (root1->val != root2->val) return false;

        // Recursively check left and right subtrees
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is null, it is trivially a subtree of any tree
        if (subRoot == nullptr) return true;

        // If root is null, subRoot cannot be a subtree
        if (root == nullptr) return false;

        // Check if the current node of root matches the subRoot
        if (isIdentical(root, subRoot)) return true;

        // Recursively check the left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
