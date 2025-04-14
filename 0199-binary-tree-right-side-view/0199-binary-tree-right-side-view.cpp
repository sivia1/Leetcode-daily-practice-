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
//doing a modified pre order traversal
//for every node we traversing its right child first then its left child, that way we first keep track and store the rightmost node 
    vector<int> ans;
    void exploreRightView(TreeNode* node, int level) {
        if(level == ans.size()) {
            ans.push_back(node->val);
        }
        if(node->right) exploreRightView(node->right, level+1);
        if(node->left) exploreRightView(node->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return ans;
        }
        exploreRightView(root, 0);
        return ans;
    }
};