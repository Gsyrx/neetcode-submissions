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
    // Map to store the index of each value in inorder traversal for O(1) lookup
    unordered_map<int, int> inorderIndexMap;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        // Base case: if the range is invalid, return null
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // The first element of the current preorder range is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in the inorder traversal
        int inRootIdx = inorderIndexMap[rootVal];
        int numsLeft = inRootIdx - inStart; // Number of nodes in the left subtree

        // Recursively build the left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + numsLeft,
                           inorder, inStart, inRootIdx - 1);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, inRootIdx + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Populate the map with inorder indices for fast lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};

