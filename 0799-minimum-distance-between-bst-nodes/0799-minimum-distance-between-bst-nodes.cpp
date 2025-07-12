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
    //using In-Order Traversal Approach
    vector<int> result;
    
    void inOrder(TreeNode* root) {
        if(!root) return;

        inOrder(root->left);
        result.push_back(root->val);
        inOrder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);

        int minDiff = INT_MAX;

        for(int i = 1; i < result.size(); i++) {
            minDiff = min(minDiff, result[i] - result[i-1]);
        }
        return minDiff;
    }
};