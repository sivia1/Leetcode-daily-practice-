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
//diameter is NOT HEIGHT --> It is the longest path between any two nodes in the tree
    int diameter = 0;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);

        diameter = max(diameter, right + left);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};