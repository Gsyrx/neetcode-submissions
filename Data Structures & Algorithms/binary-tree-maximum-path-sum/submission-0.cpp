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


    // Helper function to calculate the maximum gain (sum of the path starting from the node).
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;  // Base case: if the node is null, return 0.

        // Recursively calculate the maximum gain from the left and right subtrees.
        int leftGain = max(maxGain(node->left, maxSum), 0);  // If the left gain is negative, take 0.
        int rightGain = max(maxGain(node->right, maxSum), 0);  // If the right gain is negative, take 0.

        // Calculate the current path sum by including the node's value and both subtrees.
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum path sum.
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum gain from the current node, which can be used by its parent.
        return node->val + max(leftGain, rightGain);
    }
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Variable to store the maximum path sum.

        // Helper function to perform DFS and calculate the maximum path sum.
        maxGain(root, maxSum);

        return maxSum;
    }
};
