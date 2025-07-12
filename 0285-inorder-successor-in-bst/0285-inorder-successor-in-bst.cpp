/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//TWO VERY IMPORTANT OBSERVATION->

//SUCCESSOR of p = Node with the SMALLEST Key > p.val

//(1) --> if RIGHT SUBTREE of p exists-> Successor = leftmost node of its Right subtree

//(2) --> If P has NO right subtree then SUCESSOR is the lowest ANCESTOR where P lies in the LEFT SUBTREE
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //CASE 1: if p->right exists 
        if(p->right) { //don't check for curr->right check for p->right and then intialise curr = p->right otherwise in while loop if curr->left is false and only the right child exists we have to return that only and curr's value is not changing as we're not changing it if we don't initialise curr = p->right.
            TreeNode* curr = p->right; 
            while(curr->left) {
                curr = curr->left;
            }
           return curr; 
        }

        //CASE 2: P has NO RIGHT subtree
        TreeNode* successor = nullptr;
        TreeNode* curr = root;
        while(curr) {
            if(curr->val > p->val) {
                successor = curr;
                curr= curr->left;
            }else if (curr->val <= p->val) {
                curr = curr->right;
            }
        }
        return successor;
    }
};