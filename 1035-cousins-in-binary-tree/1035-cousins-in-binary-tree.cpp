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
//find parent and depth of nodes then compare
//Approach 1 --> DFS 
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;

        int depthX = -1, depthY = -1;

        findParentAndDepth(root, nullptr, 0, x, parentX, depthX);
        findParentAndDepth(root, nullptr, 0, y, parentY, depthY);

        return ((depthX == depthY) && (parentX != parentY));

        
    }

    void findParentAndDepth (TreeNode* node, TreeNode* parent, int depth, int target, TreeNode*& foundParent, int& foundDepth) {
        if(!node) {
            return;
        }
        if(node->val == target) {
            foundParent = parent;
            foundDepth = depth;
            return;
        }

        findParentAndDepth(node->left, node, depth+1, target, foundParent, foundDepth);
        findParentAndDepth(node->right, node, depth+1, target, foundParent, foundDepth);
    }
};