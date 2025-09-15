class Solution {
public:
//approach --> cycle detection
//Tree + 1 edge = exactly 1 cycle
//Last added edge in chronological order = redundant edge
//DFS with parent tracking (why parent tracking?) --> In undirected graph, every edge connects two nodes bidirectionally, without tracking parent, we'd "detect" a false cycle by going A->B->A
//Mark visited nodes
//Return true if revisit occur
//return cycle creator--> first edge that triggers cycle detection 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Check if this edge created a cycle
            vector <bool> visit(n+1, false);
            if(dfs(u, -1, adj, visit)) {
                return {u, v}; // Found the cycle creator!
            }
        }
        return {}; // Should never reach here
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit) {
        if(visit[node]) {
            return true; // Revisited node = cycle found!
        }
        visit[node] = true; // Mark as visited

        for(int neigh : adj[node]) {
            if(neigh == parent) { 
                continue; // Don't go back to parent (that's not a cycle)
            }

            if(dfs(neigh, node, adj, visit)) {
                return true; // Cycle found in subtree
            }
        }
        return false; // No cycle from this node
    }
    //Time: O(n²) - n iterations × O(n) DFS each
    //Space: O(n) - adjacency list + recursion stack
};