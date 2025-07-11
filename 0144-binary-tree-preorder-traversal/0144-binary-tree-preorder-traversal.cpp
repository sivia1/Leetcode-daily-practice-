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
//my intial idea is correct--> first push root, pop value, push children right then left into the stack if the exist; need to check for if root does not exist toothen push null into stack
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        TreeNode* curr = root;
        stack<TreeNode*> st;
        st.push(curr);
        vector<int> res;
        while(!st.empty()) {
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            if(curr->right) {
                st.push(curr->right);
            }
            if(curr->left) {
                st.push(curr->left);
            } 
        }
        return res;
    }
};