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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) return root;
        TreeNode *prevRootLeft = root->left, *prevRootRight  = root->right;
        TreeNode *newRoot = upsideDownBinaryTree(root->left);
        prevRootLeft->right = root;
        prevRootLeft->left = prevRootRight;

        root->left = nullptr;
        root->right = nullptr;
        return newRoot;
    }
};