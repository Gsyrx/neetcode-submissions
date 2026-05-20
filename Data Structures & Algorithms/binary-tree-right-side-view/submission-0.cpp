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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;  // To store the right side view.
        if (root == nullptr) {
            return result;  // Return empty result if the tree is empty.
        }
        
        queue<TreeNode*> q;  // Queue for level order traversal.
        q.push(root);  // Start with the root node.
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level.
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  // Get the node at the front of the queue.
                q.pop();  // Remove the node from the queue.
                
                // If this is the rightmost node at the current level, add it to the result.
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                
                // Add left and right children to the queue for the next level.
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        
        return result;  // Return the right side view of the tree.
    }
};
