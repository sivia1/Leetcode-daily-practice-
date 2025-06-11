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
//4 cases
    TreeNode* findMin(TreeNode* node) {
        while(node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //case one : not found
        if(root == NULL) {
            return root; //key doesn't exist, return NULL
        }
        if(key < root->val) {
            root->left = deleteNode(root->left, key); //go left
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); //go right
        } else {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            //node has only right child
            if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp; //replace with right child
            }
            if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp; //replace with left child
            }
            //node with both children
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};