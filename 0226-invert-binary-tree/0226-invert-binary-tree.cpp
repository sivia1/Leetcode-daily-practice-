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
//classic recursive approach
//change the pointers --> inversion can be done by changing the pointers.. you don't have to swap the nodes

//edge case --> if root is null return empty , other wise perform classic recursion
//traverse right and store in the right variable
//traverse left and store in the left variable

//Then interchange the POINTERS
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);

        root->right = left;
        root->left = right;

        return root;
    }
};