class Solution {
public:
//create adjacency list
//perform topo sort to detect cycle
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
        }
        //now perform topological sorting

        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(topo.size() == numCourses) {
            return true;
        }
        return false;
    }
};