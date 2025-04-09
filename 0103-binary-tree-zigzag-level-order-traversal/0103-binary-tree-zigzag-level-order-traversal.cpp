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
// “I’ll use a queue for the standard level order traversal, and I’ll keep a bool flag called leftToRight. If the flag is true, I add elements normally. If it’s false, I’ll reverse the current level’s values before adding them to the result. I’ll then toggle the flag after each level.”
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans; //empty result
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int>level(size);

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                level[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};