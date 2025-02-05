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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ancestors;

        // Traverse from node p to the root, adding all ancestors to the set
        while (p != nullptr) {
            ancestors.insert(p);
            p = p->parent;
        }

        // Traverse from node q to the root
        while (q != nullptr) {
            // The first common ancestor encountered is the LCA
            if (ancestors.count(q)) {
                return q;
            }
            q = q->parent;
        }

        return nullptr; // If no common ancestor is found (theoretically shouldn't happen)
    }
};