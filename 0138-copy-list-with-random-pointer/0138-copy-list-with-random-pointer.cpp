/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* curr = head;
        //in the first pass copy all the nodes without next and random pointers
        while(curr != NULL) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        //In second pass copy all the random and next pointers
        curr = head;
        while(curr != NULL) {
            map[curr]->random = map[curr->random];
            map[curr]->next = map[curr->next];
            curr = curr->next;
        }
        return map[head];
    }
};