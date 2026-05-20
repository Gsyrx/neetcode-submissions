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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // To store the level order traversal result.
        if (root == nullptr) {
            return result;  // Return empty result if the tree is empty.
        }
        
        queue<TreeNode*> q;  // Queue to store nodes for level order traversal.
        q.push(root);  // Start with the root node.
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level.
            vector<int> levelValues;   // To store values of nodes at the current level.
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  // Get the node at the front of the queue.
                q.pop();  // Remove the node from the queue.
                
                levelValues.push_back(node->val);  // Add the node's value to the result.
                
                // If the node has a left child, add it to the queue.
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                // If the node has a right child, add it to the queue.
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            result.push_back(levelValues);  // Add the current level's values to the result.
        }
        
        return result;  // Return the final level order traversal.
    }
};
