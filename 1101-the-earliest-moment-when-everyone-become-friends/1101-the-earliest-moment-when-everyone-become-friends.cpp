class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> adj(n);
        
        

        for(int i = 0; i < logs.size(); i++) {
            vector<bool> visited(n, false);
            int u = logs[i][0];
            int v = logs[i][1];
            int w = logs[i][2];

            adj[v].push_back(w);
            adj[w].push_back(v);

            int cnt = 0;
            dfs(0, adj, visited, cnt);
            if(cnt == n) {
                return u;
            }
        }
        return -1;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int &cnt) {
        visited[node] = true;
        cnt++;

        for(int neigh : adj[node]) {
            if(!visited[neigh]) {
                dfs(neigh, adj, visited, cnt);
            }
        }
    }
};