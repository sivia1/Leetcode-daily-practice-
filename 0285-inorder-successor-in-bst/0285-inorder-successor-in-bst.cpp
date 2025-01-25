/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        if(p->right) {
            TreeNode* curr = p->right;
            while(curr->left) {
                curr = curr->left;
            }
            return curr;
        }

        TreeNode* curr = root;
        while(curr) {
            if(p->val < curr->val) {
                successor = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return successor;
    }
};