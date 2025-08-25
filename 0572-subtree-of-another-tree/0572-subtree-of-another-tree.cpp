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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) {
            return false;
        }
        //Match found?
        if(isSame(root, subRoot)) {
            return true;
        }
        //Not found? recursively keep looking
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL || s->val != t->val) {
            return false;
        }
        //left with left and right with right
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};