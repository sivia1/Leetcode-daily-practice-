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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* current = root;
        while(current) {
            if(val < current->val) {
                if(current->left == NULL) {
                    current->left = new TreeNode(val);
                    return root;
                }
                current = current->left;
            } else {
                if(current->right == NULL) {
                    current->right = new TreeNode(val);
                    return root;
                }
                current = current->right;
            }
        }
        return root;
        //TC --> O (H) where H is height of the tree
        //SC --> O (H) for call stack
    }
};