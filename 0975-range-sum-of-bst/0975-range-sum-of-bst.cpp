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
//Approach --> leverage the BST property and prune entire subtrees that cannot possibly contain nodes within the desired range [low, high]
//visit the nodes only in the relevant part of the tree
//start at root and maintain a running sum
//calculate the curr node's values (node->val):
    // if low <= node->val <= high, add node->val to the sum.
    // Decide which subtrees to traverse:
        //Left Subtree --> if node->val > low it's possible that values in the left subtree could still be >= low, so traverse the left child.
        //If node->val < low then all values in the left subtree will also be < low, so you can skip the left subtree 

        //Right Subtree --> if node-> val < high it's possible that values in the right subtree(which are larger) could still be <= high, so you must traverse the right child.
        //If node->val > high then all values in the right subtree will also be > high, so you can skip the right subtree
    int rangeSumBST(TreeNode* root, int low, int high) {
        //base case
        if(root == nullptr) {
            return 0;
        }

        int currSum = 0;
        if(root->val >= low && root->val <= high) {
            currSum += root->val;
        }
        // 2. Decide on the left traversal (Pruning)
        // If the current node's value is > low, the left child MIGHT still be >= low.
        // We only traverse left if it's possible for the left subtree to contain relevant nodes
        if(root->val > low) {
            currSum += rangeSumBST(root->left, low, high);
        }

        // 3. Decide on the right traversal (Pruning)
        // If the current node's value is < high, the right child MIGHT still be <= high.
        // We only traverse right if it's possible for the right subtree to contain relevant nodes
        if(root->val < high) {
            currSum += rangeSumBST(root->right, low, high);
       }
       return currSum;
    }
};

//This pruning technique ensures you only visit the nodes in the relevant part of the tree, potentially reducing the time complexity from O(N) to O(K + H) (where K is the number of nodes in the range and H is the tree height, as you might traverse down to find the range boundaries), and the space complexity (due to recursion stack) is $O(H)$, which is more efficient than O(N) space.