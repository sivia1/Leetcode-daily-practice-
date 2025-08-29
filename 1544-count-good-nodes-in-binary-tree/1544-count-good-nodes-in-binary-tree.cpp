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
//approach --> //intuition: keep track of the maximum value encountered so far in the path from root to the node 
//A node is good if it's value is greater than or equal to maxSoFar
//Recursively check it's children with the updated maxSoFar
//perform DFS + recursion, traverse all paths in the tree
//for each path from root to a node, check if current node's value is > or equal to all values in a path
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return good;
    }
    int good = 0;
    void dfs(TreeNode* node, int maxSoFar) {
        if(node->val >= maxSoFar) {
            good++;
        }
        if(node->right) {
            dfs(node->right, max(maxSoFar, node->val));
        }
        if(node->left) {
            dfs(node->left, max(maxSoFar, node->val));
        }
    }
};