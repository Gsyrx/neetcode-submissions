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

int dfs(TreeNode* node, int& diameter) {
        if (!node) return 0;  // Base case: if node is null, return 0
        
        // Recursively compute the depth of the left and right subtrees
        int leftDepth = dfs(node->left, diameter);
        int rightDepth = dfs(node->right, diameter);
        
        // Update the diameter (sum of left and right depths)
        diameter = max(diameter, leftDepth + rightDepth);
        
        // Return the depth of the node: 1 + the maximum depth of its subtrees
        return 1 + max(leftDepth, rightDepth);
    }

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // To store the maximum diameter
        
        // Call DFS to start the recursion
        dfs(root, diameter);
        
        // Return the maximum diameter
        return diameter;
    }
};
