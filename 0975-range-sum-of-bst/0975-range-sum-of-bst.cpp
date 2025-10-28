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
    //initial idea is to traverse inorder store the nodes in the array and find the sum b/w low and high
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> sortedValues;

        inOrder(root, sortedValues);
        int totalSum = 0;

        for(int val : sortedValues) {
            if(val >= low && val <= high) {
                totalSum += val;
            } else if (val > high) {
                break;
            }
        }
        return totalSum;
    }

    void inOrder(TreeNode* node, vector<int>& store) {
        if(node == nullptr) {
            return;
        }

        inOrder(node->left, store);
        store.push_back(node->val);
        inOrder(node->right, store);
    }

    //This is correct but less optimal because it visits every single node in the tree and uses O(N) extra space to store the vector, regardless of how small the required range is.
};