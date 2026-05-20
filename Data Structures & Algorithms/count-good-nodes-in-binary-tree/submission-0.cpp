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

int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0; // Base case: if the node is null, return 0.

        int count = 0;
        if (node->val >= maxVal) {
            count = 1; // The current node is good, so increment the count.
        }

        // Update the maximum value encountered on the path and continue DFS.
        maxVal = max(maxVal, node->val);

        // Recursively call dfs for left and right children.
        count += dfs(node->left, maxVal);
        count += dfs(node->right, maxVal);

        return count;
    }

class Solution {
public:
    int goodNodes(TreeNode* root) {
        // Start the DFS with the root node, and initialize the max value as root's value.
        return dfs(root, root->val);
    }
};
