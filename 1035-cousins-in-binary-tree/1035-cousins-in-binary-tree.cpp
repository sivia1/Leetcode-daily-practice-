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
//level order traversal-->BFS approach
    bool isCousins(TreeNode* root, int x, int y) {
        //base case
        if(!root) {
            return false; 
        }
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        
        while(!q.empty()) {
            int size = q.size();
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;
            bool foundX = false, foundY = false;

            //process all nodes at current level
            for(int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if(node->val == x) {
                    foundX = true;
                    parentX = parent;
                }
                if(node->val == y) {
                    foundY = true;
                    parentY = parent;
                }
                //add children to queue for next level
                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }

            //if both found at same level/depth check for different parents, please don't put == in-place of &&, it does not continue the search
            if(foundX && foundY) {
                return parentX != parentY;
            }
            //if only one is found, they can't be cousins
            if(foundX || foundY) {
                return false;
            }
        }
        return false;
    }
};