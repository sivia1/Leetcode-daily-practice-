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
//understanding the problem--> you need to find all the nodes at a k distance from the target node, might be up or down. You cannot traverse child to parent in a BT so Convert it to a Undirected graph

//Convert Binary Tree to an Undirected graph
//then perform BFS from the target node :
    //BFS naturally explodes all nodes by distance [level by level]
    //Stop when you reach distance k and return all nodes at this distance

    void buildGraph(TreeNode* current, TreeNode* parent, unordered_map<int, unordered_set<int>>& map) {
        if(!current) {
            return;
        }
        if(map.find(current->val) == map.end()) {
            map[current->val] = unordered_set<int>();
        }
        if(parent) {
            map[current->val].insert(parent->val);
            map[parent->val].insert(current->val); //bidirectional
        }

        if(current->left) buildGraph(current->left, current, map);
        if(current->right) buildGraph(current->right, current, map);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, unordered_set<int>> map;
        buildGraph(root, 0, map);

        //STEP 2 perform BFS
        //initialise queue
        queue<int> q;
        q.push(target->val);
        //a visited array to mark the visited nodes or neighbours
        unordered_set<int> visited;
        visited.insert(target->val);
        int level = 0;// to keep track of the level

        //1
        while(!q.empty()) {
            int size = q.size();

            //if we find level == k then we return all the nodes at that level
            //3
            if(level == k) {
                vector<int> result; //to store the nodes at level k
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    result.push_back(node);
                }
                return result;
            }
            //3 ends here

            //process nodes at each level
            //2
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for(auto neighbour : map[node]) {
                    //check for neighbours visited for node
                    if(visited.find(neighbour) == visited.end()) {
                        //if not marked as visited then push into the queue and mark visited
                        q.push(neighbour);
                        visited.insert(neighbour);

                    }
                }
            }
            level++; //after processing all the nodes in curr level increment level
            //2 ends here
        }
        return {};
    }
};