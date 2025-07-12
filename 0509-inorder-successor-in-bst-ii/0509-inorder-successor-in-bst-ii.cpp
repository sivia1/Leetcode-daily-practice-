/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // CASE 1: If node has right subtree
        // Successor = leftmost node in right subtree
        if (node->right) {
            Node* curr = node->right;
            while (curr->left) {
                curr = curr->left;
            }
            return curr;
        }
        
        // CASE 2: No right subtree
        // Successor = lowest ancestor where node lies in LEFT subtree
        // Use parent pointers to traverse upward
        Node* curr = node;
        Node* parent = node->parent;
        
        // Keep going up until we find an ancestor where current node
        // is in the left subtree (i.e., parent->left == curr)
        while (parent && parent->right == curr) {
            curr = parent;
            parent = parent->parent;
        }
        
        return parent; // This will be null if no successor exists
    }
};